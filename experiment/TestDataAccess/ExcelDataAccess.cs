using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.OleDb;
using Dapper;
using System.Configuration;
using ExperimentForLPP.Classes;
using System.Collections.Generic;
using System.Data;

namespace ExperimentForLPP
{
    class ExcelDataAccess
    {
        public static OleDbConnection TestDataFileConnection()
        {
            OleDbConnection  oledbConn  = null;
            var fileName = ConfigurationManager.AppSettings["TestDataSheetPath"];
            var con = string.Format(@"Provider=Microsoft.ACE.OLEDB.12.0;Data Source = {0}; Extended Properties=Excel 12.0;", fileName);
            oledbConn = new OleDbConnection(con);
            oledbConn.Open();
            return oledbConn;
        }


        public static IList<T> ExtractExcel<T>(int n, OleDbConnection oledbConn)
        {
            OleDbCommand cmd = new OleDbCommand(); 
            OleDbDataAdapter oleda = new OleDbDataAdapter();
            DataSet dsInfo = new DataSet();
            cmd.Connection = oledbConn;
            cmd.CommandType = CommandType.Text;
            IList<T> data = new List<T>();
            if (n == 1)
            {
                cmd.CommandText = "select * from [GaInAllPath$]";
                oleda = new OleDbDataAdapter(cmd);
                oleda.Fill(dsInfo, "GaInAllPath");
                List<GaInAllPath> dsInfoList = dsInfo.Tables[0].AsEnumerable().Select(s => new GaInAllPath
                {
                   Name = Convert.ToString(s["Name"] != DBNull.Value ? s["Name"] : ""),
                   PopulationSize = Convert.ToInt32(s["PopulationSize"]),
                   graph = Convert.ToString(s["graph"]),
                   numVertex = Convert.ToInt32(s["numVertex"]),
                   numEdge = Convert.ToInt32(s["numEdge"]),
                   numberStep = Convert.ToInt32(s["numberStep"] != DBNull.Value ? s["numberStep"] : null),
                   persentToCross = Convert.ToDouble(s["persentToCross"])
                }).ToList();

                data = (IList<T>)Convert.ChangeType(dsInfoList, typeof(List<T>));
                //   List<T> objList = (List<T>)dsInfoList;
                  // IEnumerable<GaInAllPath> list = objList.Cast<GaInAllPath>();
                  // IList<T> s2 = objList.ConvertAll(x => x as T); //succeeds
                
            }
            else if (n==2)
            {
                cmd.CommandText ="select * from [GaBetweenVertex$]";
                oleda = new OleDbDataAdapter(cmd);
                oleda.Fill(dsInfo, "GaBetweenVertex");

                List<GaBetweenVertex> dsInfoList = dsInfo.Tables[0].AsEnumerable().Select(s => new GaBetweenVertex
                {
                    PopulationSize = Convert.ToInt32(s["PopulationSize"]),
                    graph = Convert.ToString(s["graph"]),
                    numVertex = Convert.ToInt32(s["numVertex"]),
                    numEdge = Convert.ToInt32(s["numEdge"]),
                    numberStep = Convert.ToInt32(s["numberStep"] != DBNull.Value ? s["numberStep"] : null),
                    firstVertex = Convert.ToInt32(s["firstVertex"]),
                    secondVertex = Convert.ToInt32(s["secondVertex"])
                }).ToList();

                data = (IList<T>)Convert.ChangeType(dsInfoList, typeof(List<T>));
            }
            return data;
            
        }


        public static IList<T> ReadExcel<T>(int i) 
        {
            IList<T> data = new List<T>();
            OleDbConnection oledbConn = TestDataFileConnection();
            if (oledbConn.State == ConnectionState.Open)
            { 
                if (i == 1)
                {
                    IList<GaInAllPath> objInfo = ExcelDataAccess.ExtractExcel<GaInAllPath>(i, oledbConn);
                    data = (IList<T>)Convert.ChangeType(objInfo, typeof(List<T>));
                }
                else if (i == 2)
                {
                    IList<GaBetweenVertex> objInfo = ExcelDataAccess.ExtractExcel<GaBetweenVertex>(i, oledbConn);
                    data = (IList<T>)Convert.ChangeType(objInfo, typeof(List<T>));
                }
                oledbConn.Close();
            }
            else
            {
                throw (new Exception("Error connection!"));
            }

            return data;
        }


    }
}