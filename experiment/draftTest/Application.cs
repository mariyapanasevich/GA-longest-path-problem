using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using OpenQA.Selenium;
using OpenQA.Selenium.Remote;
using OpenQA.Selenium.Support.PageObjects;

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
        [FindsBy(How = How.Id, Using = "dataGridView1")]
        public IWebElement dataGrid { get; set; }
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

        public void longestPathinAllGraph()
        {
            //to do...
        }

        public void longestPathinBetweenVertex()
        {
           // numVertex.SendKeys("21");
        }




    }
}
