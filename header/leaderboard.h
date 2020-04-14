#ifndef LEADERBOARD_H
#define LEADERBOARD_H

#include "vecteur.h"
#include <QObject>
#include <QString>
#include <QTableView>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QAbstractTableModel>

const int ROWS = 100;
const int COLS = 2;

class LeaderboardEntry
{
public:
	QString name = "";
	qint16 score = 0;
	bool initialized = false;
};

class LeaderboardTableModel : public QAbstractTableModel
{
	Q_OBJECT
public:
	LeaderboardTableModel(QObject* parent = 0) : QAbstractTableModel(parent) {};
	int rowCount(const QModelIndex &parent = QModelIndex()) const override { return 100; };
	int columnCount(const QModelIndex &parent = QModelIndex()) const override { return 2; };
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
	void insert(LeaderboardEntry entry);
	void overwriteData();
private:
	QString _tableData[ROWS][COLS];
	int _nElements = 0;
};

class LeaderboardTable : public QTableView
{
public:
	LeaderboardTable(QWidget* parent = 0);
	~LeaderboardTable();
	void insert(LeaderboardEntry entry);
private:
	void _insertAll();
	void _insert(LeaderboardEntry entry);
	std::string _filePath = "assets/Leaderboard";
	LeaderboardTableModel _leaderboardTableModel;
	Vecteur<LeaderboardEntry> _tableData;
	bool _written = false;
	void loadFile(std::string filePath);
	void saveToFile(std::string filePath);
};

class Leaderboard : public QGraphicsView
{
public:
	Leaderboard();

private:
	LeaderboardTable* _leaderboardTable;
	QGraphicsScene* _leaderboardScene;
};

#endif