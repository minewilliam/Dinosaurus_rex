#include "header/leaderboard.h"
#include <fstream>

QVariant LeaderboardTableModel::data(const QModelIndex &index, int role) const
{
	if (role == Qt::DisplayRole)
	{
		if (index.row() < ROWS && index.column() < COLS)
		{
			return _tableData[index.row()][index.column()];
		}
		else
		{
			return QString("-");
		}
	}
	return QVariant();
}

QVariant LeaderboardTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
		switch (section) {
		case 0:
			return QString("Score");
		case 1:
			return QString("Name");
		}
	}
	else if (role == Qt::DisplayRole && orientation == Qt::Vertical)
	{
		return QString::number(section+1);
	}
	return QVariant();
}

void LeaderboardTableModel::insert(LeaderboardEntry entry)
{
	_tableData[_nElements][0] = QString::number(entry.score);
	_tableData[_nElements][1] = entry.name;
	_nElements++;
}

void LeaderboardTableModel::overwriteData()
{
	_nElements = 0;
}

LeaderboardTable::LeaderboardTable(QWidget* parent) : QTableView(parent)
{
	setShowGrid(false);
	setModel(&_leaderboardTableModel);
	loadFile(_filePath);
}

LeaderboardTable::~LeaderboardTable()
{
	if (_written)
	{
		saveToFile(_filePath);
	}
}

void LeaderboardTable::saveToFile(std::string filePath)
{
	std::ofstream file(filePath);

	for(int i = 0; i < _tableData.size(); i++)
	{
		file << _tableData[i].name.toStdString() << ";" << _tableData[i].score;
		if (i != _tableData.size() - 1) file << std::endl;
	}
}

void LeaderboardTable::loadFile(std::string filePath)
{
	std::ifstream file(filePath);
	std::string line;

	while (std::getline(file, line))
	{
		LeaderboardEntry newEntry;

		//Load entries from file
		int i = 0;
		for (; i < line.length(); i++)
		{
			char c = line[i];
			if (c == ';') break;
			newEntry.name += c;
		}
		i++;
		std::string k = "";
		for (; i < line.length(); i++)
		{
			char c = line[i];
			k += c;
		}
		newEntry.score = std::stoi(k);

		_insert(newEntry);
	}
	_insertAll();
}

void LeaderboardTable::insert(LeaderboardEntry entry)
{
	_written = true;
	_insert(entry);
}

void LeaderboardTable::_insertAll()
{
	for (int j = 0; j < _tableData.size() && j < ROWS; j++)
	{
		_leaderboardTableModel.insert(_tableData[j]);
	}
}

void LeaderboardTable::_insert(LeaderboardEntry entry)
{
	int index = 0;
	bool indexFound = false;
	while (!indexFound)
	{
		if(index >= _tableData.size())
		{
			indexFound = true;
		}
		else if (_tableData[index].score >= entry.score)
		{
			index++;
		}
		else
		{
			indexFound = true;
		}
	}

	if (index >= _tableData.size())
	{
		_tableData.insert(new LeaderboardEntry());
	}
	else if (_tableData[index].initialized)
	{
		_insert(_tableData[index]);
	}

	_tableData[index] = entry;
	_tableData[index].initialized = true;
	if (_written)
	{
		_leaderboardTableModel.overwriteData();
		_insertAll();
		saveToFile(_filePath);
		selectRow(index);
	}
}