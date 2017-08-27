#include <string>
#include "libpq-fe.h"
#include "DatabaseWriter.h"
#include <windows.h>
#include <iostream>
#include <msclr\marshal_cppstd.h>


using namespace System::Windows::Forms;
using namespace std;
using namespace System;
using namespace msclr::interop;

const char* CONNECTIONSTRING = "hostaddr = '127.0.0.1' port = '5433' dbname = 'GA' user = 'postgres' password = 'ermolaeva7' connect_timeout = '0'";

void DatabaseWriter::CloseConn(PGconn *conn)
{
	PQfinish(conn);
	getchar();

}

PGconn* DatabaseWriter::ConnectDB()
{
	conn = NULL;
	statusConnect = true;

	conn = PQconnectdb(CONNECTIONSTRING);

	if (PQstatus(conn) != CONNECTION_OK)
	{
		statusConnect = false;
		CloseConn(conn);
	}

	return conn;
}

void DatabaseWriter::error(string mess)
{
	String^ res1 = marshal_as<String^>(mess);
	MessageBox::Show(res1 , "Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);	
	exit(1);
}