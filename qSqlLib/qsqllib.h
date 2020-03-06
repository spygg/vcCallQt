#ifndef QSQLLIB_H
#define QSQLLIB_H


#include "include/qsqldatabase.h"
#include "include/qsqlquery.h"
#include "include/qsqldriver.h"
#include "include/qsqlerror.h"
#include "include/qsqlrecord.h"
#include "include/qvariant.h"



#if defined(QSQLLIB_LIBRARY)
#define QSQLLIBSHARED_EXPORT  __declspec(dllexport)
#else
#define QSQLLIBSHARED_EXPORT  __declspec(dllimport)
#endif




class QSQLLIBSHARED_EXPORT CSql
{
public:
	CSql();
	~CSql();


	bool exec( QSqlQuery *query, QString queryString);
	void closeDataBase();
	bool connectDataBase(QString dbName,
		QString type = "QSQLITE",
		QString host = "127.0.0.1",
		int port = -1,
		QString userName = "",
		QString passWd = "");

	QString lastError();
	QStringList drivers();
	QSqlDatabase *dataBase();
	QSqlRecord tableInfo(QString table);
	QStringList tables();
private:

	QSqlDatabase m_db;
	QStringList m_tables;
};


#if !defined(QSQLLIB_LIBRARY)
#ifdef _DEBUG
#pragma comment(lib, "lib/qSqlLibd.lib")
#pragma comment(lib, "lib/QtSqld4.lib")
#pragma comment(lib, "lib/QtCored4.lib")
#else
#pragma comment(lib, "lib/qSqlLib.lib")
#pragma comment(lib, "lib/QtSql4.lib")
#pragma comment(lib, "lib/QtCore4.lib")
#endif
#endif

#endif // QSQLLIB_H
