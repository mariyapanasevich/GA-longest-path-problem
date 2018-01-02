using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenQA.Selenium;
using OpenQA.Selenium.Remote;
using OpenQA.Selenium.Support.PageObjects;
using System.Web.UI;
using System.Text.RegularExpressions;
using OpenQA.Selenium.Support.UI;
using System.Threading;
using ExperimentForLPP.Classes;
using ExperimentForLPP.Configurations;

namespace ExperimentForLPP
{
    public class Application
    {
       
        private IWebDriver driver;

        [FindsBy(How = How.Id, Using = "textBox1")]
        public IWebElement numVertex { get; set; }

        [FindsBy(How = How.Id, Using = "textBox2")]
        public IWebElement numEdge { get; set; }

        [FindsBy(How = How.Id, Using = "textBox3")]
        public IWebElement SizePop { get; set; }

        [FindsBy(How = How.Id, Using = "textBox4")]
        public IWebElement persentCrossover { get; set; }

        [FindsBy(How = How.Id, Using = "textBox5")]
        public IWebElement numStep { get; set; }

        [FindsBy(How = How.Id, Using = "textBox7")]
        public IWebElement firstVertex { get; set; }

        [FindsBy(How = How.Id, Using = "textBox6")]
        public IWebElement secondVertex { get; set; }

        [FindsBy(How = How.Id, Using = "checkBox1")]
        public IWebElement AllPath { get; set; }

        [FindsBy(How = How.Id, Using = "checkBox2")]
        public IWebElement betweenVertex { get; set; }

        [FindsBy(How = How.Id, Using = "radioButton1")]
        public IWebElement nonintersectingpaths { get; set; }

        [FindsBy(How = How.Id, Using = "radioButton2")]
        public IWebElement intersectingpaths { get; set; }

        [FindsBy(How = How.Id, Using = "radioButton3")]
        public IWebElement mutate { get; set; }

        [FindsBy(How = How.Id, Using = "radioButton4")]
        public IWebElement noninterAndinterpaths { get; set; }

        [FindsBy(How = How.Id, Using = "button1")]
        public IWebElement start { get; set; }

        [FindsBy(How = How.Id, Using = "button2")]
        public IWebElement clear { get; set; }

        [FindsBy(How = How.Id, Using = "dataGridView1")]
        public IWebElement dataGrid { get; set; }
    //    private int num;
        public Application(IWebDriver driver)
        {
            this.driver = driver;
            PageFactory.InitElements(driver, this);
//            num = 0;
        }

        public void findlongestPath(int type, GA obj)
        {
            numVertex.SendKeys(obj.numVertex.ToString());
            numEdge.SendKeys(obj.numEdge.ToString());
            List<List<int>> dataTable = stringToList(obj);
            SizePop.SendKeys(obj.PopulationSize.ToString());
            this.setValue(dataTable);

            try
            {

                if (type == 1)
                {
                    var data = (GaInAllPath)obj;
                  
                    AllPath.Click();
                    data.setTypeAlgorithm();

                    switch(data.typeAlgorithm)
                    {
                        case 1:    
                        nonintersectingpaths.Click();
                        break;
                        case 2:
                        intersectingpaths.Click();
                        break;
                        case 3:
                        mutate.Click();
                        break;
                        case 4:
                        noninterAndinterpaths.Click();
                        break;
                        default:
                        throw new Exception("Algorithm didn't find!");
                        break;
                    }
                    persentCrossover.SendKeys(data.persentToCross.ToString());
                    if (data.typeAlgorithm == 3 || data.typeAlgorithm == 4)
                    {
                        numStep.SendKeys(data.numberStep.ToString());
                    }

                }
                else if (type == 2)
                {
                    var data = (GaBetweenVertex)obj;
                    betweenVertex.Click();
                    numStep.SendKeys(data.numberStep.ToString());
                    firstVertex.SendKeys(data.firstVertex.ToString());
                    secondVertex.SendKeys(data.secondVertex.ToString());
                }
                else
                {
                    throw new Exception("Task didn't find!");
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine("Error:" + ex.Message);
            }

        }

        public void setValue(List<List<int>> element)
        {
            for (int i = 0; i < element.Count(); i++)
            {
                List<string> list = new List<string>(2);
                list.Add("First vertex Строка " + i.ToString());
                list.Add("Second vertex Строка " + i.ToString());

                for (int j = 0; j < list.Count(); j++)
                {
                    IWebElement obj = driver.FindElement(By.Name(list[j]));
                    obj.SendKeys(element[i][j].ToString());
                }
            }
        }

        public List<List<int>> stringToList(GA obj1)
        {
            List<string> tmp1 = obj1.graph.Split(new Char[] { '\n' }).ToList();

            List<List<int>> result = new List<List<int>>();
            for (int i = 0; i < tmp1.Count(); i++)
            {
                result.Add(tmp1[i].Split(new char[] { ' ' }).ToList().ConvertAll(s => Int32.Parse(s)));
            }
            return result;
        }


        public void cycleStart<T>(int i, int time, int cycle)
        {
            IList<T> data = new List<T>();

            if (i == 1)
            {
                IList<GaInAllPath> objInfo = ExcelDataAccess.ReadExcel<GaInAllPath>(i);
                data = (IList<T>)Convert.ChangeType(objInfo, typeof(List<T>));
            }
            else if (i == 2)
            {
                IList<GaBetweenVertex> objInfo = ExcelDataAccess.ReadExcel<GaBetweenVertex>(i);
                data = (IList<T>)Convert.ChangeType(objInfo, typeof(List<T>));
            }

            for (int j = 0; j < data.Count; j++)
            {
                GA dt;
                if (i == 1) dt = (GaInAllPath)Convert.ChangeType(data[j], typeof(GaInAllPath));
                else dt = (GaBetweenVertex)Convert.ChangeType(data[j], typeof(GaBetweenVertex));
                int num = 0;
                findlongestPath(i, dt);
                do
                {
                    start.Click();
                    Thread.Sleep(time * 100);
                    num++;
                }
                while (num < cycle);
                driver.Close();
                if (j + 1 != data.Count)
                {
                    Setting set = new Setting();
                    Application app = set.open();
                }
            }
        }

    }
}