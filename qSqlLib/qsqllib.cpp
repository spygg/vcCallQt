#include "qsqllib.h"

#include <QCoreApplication>
#include <QDir>


/*
 * 1.解压instantclient10_1.zip到当前文件夹
 * 2.在path中添加该解压路径xxxx\instantclient10_1 如C:\instantclient10_1
 * 3.运行odbc_install.exe
 * 4.设置环境变量NLS_LANG为SIMPLIFIED CHINESE_CHINA.AL32UTF8
 *
 * 5.在当前文件夹下建立文件tnsnames.ora内容如下(这一步如果已经安装平台则不需要)
 * ORA8 =
 *   (DESCRIPTION =
 *     (ADDRESS = (PROTOCOL = TCP)(HOST = 200.200.5.119)(PORT = 1521))
 *     (CONNECT_DATA =
 *       (SERVER = DEDICATED)
 *       (SERVICE_NAME = ora8)
 *     )
 *   )
 * 6 同时将数据库名改写为DRIVER={Oracle in instantclient10_1};DBQ=ORA8; 注意此句中的DBQ(针对没有安装平台的ODBC, OCI 直接填写用户名即可
 *  完整连接字符串 DRIVER={Oracle in instantclient10_1};UID=username;DBQ=ORA8;SERVER=ORA8;PWD=password;
 * 测试:
 * select * from LJBD_HC_BWTGGL_BWJL
 * select * from LJBD_HC_BWTGGL_YYMC
 *
 * 获取环境变量 qgetenv
 * 设置环境变量 qputenv
 * ps:
 *  已安装平台会有乱码
 */

CSql::CSql()
{

}

CSql::~CSql()
{
	if(m_db.isOpen()){
		closeDataBase();
	}
}

void CSql::closeDataBase()
{
    {
        QString connectionName = m_db.connectionName();
        m_db.close();

        m_db = QSqlDatabase();
        QSqlDatabase::removeDatabase(connectionName);
    }
}


bool CSql::connectDataBase(QString dbName, QString type,
											QString host, int port,
											QString userName, QString passWd)
{
	QCoreApplication::addLibraryPath(QDir::toNativeSeparators(QCoreApplication::applicationDirPath()));
	QCoreApplication::addLibraryPath(QDir::toNativeSeparators("./"));
	//关闭已有连接,将m_db重置
	closeDataBase();

	m_db = QSqlDatabase::addDatabase(type);

	m_db.setHostName(host);
	m_db.setPort(port);
	m_db.setUserName(userName);
	m_db.setPassword(passWd);
	m_db.setDatabaseName(dbName);

	if (!m_db.open()) {
		//关闭数据库,必须这样..
		closeDataBase();

		return false;
	}


	if(type.compare("QOCI") == 0 || type.compare("QODBC") == 0){
		QStringList tl;
		QSqlQuery query;
		const QLatin1String tableQuery("select table_name from user_tables");
		exec(&query, tableQuery);
		while (query.next()) {
			tl.append(query.value(0).toString());
		}

		m_tables = tl;
		
	}
	else{
		m_tables = m_db.tables();
	}


    return true;
}


QSqlDatabase *CSql::dataBase()
{
    return &m_db;
}

QSqlRecord CSql::tableInfo(QString table)
{
    //开启事务
    m_db.transaction();
    QSqlRecord record =  m_db.record(table);
    m_db.commit();


    return record;
}

QStringList CSql::tables()
{
    return m_tables;
}

QStringList drivers()
{
	return QSqlDatabase::drivers();
}


bool CSql::exec( QSqlQuery *query, QString queryString)
{
	bool bok = false;

	//开启事务
	m_db.transaction();

	if(!queryString.isEmpty()){
		bok = query->exec(queryString);
	}
	else{
		bok = query->exec();
	}

	m_db.commit();

	return bok;
}

QString CSql::lastError()
{
    return m_db.lastError().text();
}




