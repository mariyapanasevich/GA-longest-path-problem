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
 
namespace ExperimentForLPP
{
    class Application
    {
        private IWebDriver driver;

        [FindsBy(How = How.Id, Using = "textBox1")]
        public IWebElement numVertex {get; set;}

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
        
        [FindsBy(How = How.Id, Using = "listBox1")]
        public IWebElement result { get; set; }
        
        [FindsBy(How = How.Id, Using = "button1")]
        public IWebElement start { get; set; }

        public Application(IWebDriver driver)
        {
            this.driver = driver;
            PageFactory.InitElements(driver, this);
        }

        public void findlongestPath(int type, int time)
        {
           

            try
            {
                if (type == 1)
                {
                    GaInAllPath data = ExcelDataAccess.GetTestData<GaInAllPath>(type);
                    numVertex.SendKeys(data.numVertex.ToString());
                    numEdge.SendKeys(data.numEdge.ToString());
                    SizePop.SendKeys(data.PopulationSize.ToString());
                    List<List<int>> dataTable = stringToList(data.graph, data.numEdge);
                    setValue(dataTable);
                   
                    AllPath.Click();
                    data.setTypeAlgorithm();

                    if (data.typeAlgorithm == 1)
                    {
                        nonintersectingpaths.Click();
                    }
                    else if (data.typeAlgorithm == 2)
                    {
                        intersectingpaths.Click();
                    }
                    else if (data.typeAlgorithm == 3)
                    {
                        mutate.Click();
                    }
                    else if (data.typeAlgorithm == 4)
                    {
                        noninterAndinterpaths.Click();
                    }
                    else
                    {
                        throw new Exception("Algorithm didn't find!");
                    }

                    persentCrossover.SendKeys(data.persentToCross.ToString());
                    if (data.typeAlgorithm == 3 || data.typeAlgorithm == 4)
                    {
                        numStep.SendKeys(data.numberStep.ToString());
                    }
                }
                else if (type == 2)
                {
                    GaBetweenVertex data = ExcelDataAccess.GetTestData<GaBetweenVertex>(type);
                    numVertex.SendKeys(data.numVertex.ToString());
                    numEdge.SendKeys(data.numEdge.ToString());
                    SizePop.SendKeys(data.PopulationSize.ToString());
                    List<List<int>> dataTable = stringToList(data.graph, data.numEdge);
                    setValue(dataTable);
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

            start.Click();
            Thread.Sleep(time*1000);
           
        }

        public  void Click(IWebElement element, int timeout)
        {
            var wait = new DefaultWait<IWebElement>(element);
            wait.IgnoreExceptionTypes(typeof(WebDriverException));
            wait.PollingInterval = TimeSpan.FromMilliseconds(10);
            wait.Timeout = TimeSpan.FromSeconds(timeout);
            wait.Until<bool>(drv =>
            {
                element.Click();
                return true;
            });
        }

        public void setValue(List<List<int>> element)
        {
            for (int i = 0; i < element.Count(); i++)
            {
                string tmp = "Строка " + i.ToString();

                List<IWebElement> obj = driver.FindElement(By.Name(tmp)).FindElements(By.Name(" " + tmp)).ToList();
                for(int j=0; j < obj.Count(); j++ )
                {
                    obj[j].SendKeys(element[i][j].ToString());
                }   
            }
        }

        public List<List<int>> stringToList(string value, int numEdge)
        {
            List<string> tmp1=  value.Split( new Char[]{'\n'}).ToList();

            List<List<int>> result = new List<List<int>>();
            for (int i = 0; i < tmp1.Count(); i++)
            {
                result.Add(tmp1[i].Split(new char[] { ' ' }).ToList().ConvertAll(s => Int32.Parse(s)));
            }
            return result;
        }
    }
}
