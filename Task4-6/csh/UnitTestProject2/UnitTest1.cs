using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using part2csh;
namespace UnitTestProject2
{
    [TestClass]
    public class UnitTest1
    {
        double[] array = new double[4] { 1, 2, 3, 4 };
        [TestMethod]
        public void TestInput1()
        {
            LinearEquation l1 = new LinearEquation(3);
            Assert.AreEqual(l1.indexes[0], l1.indexes[1]);
        }
        [TestMethod]
        public void TestInput2()
        {
            LinearEquation l1 = new LinearEquation("1,2 2,1 3 4", 4);
            Assert.AreEqual(l1.indexes[0], 1,2);
        }
        [TestMethod]
        public void TestInput3()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            Assert.AreEqual(l1.indexes[0], 1.0);
        }
        [TestMethod]
        public void TestSet1()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            l1.SetIndexes(1);
            Assert.AreEqual(l1.indexes[3], 1.0);
        }
        [TestMethod]
        public void TestSet2()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            l1.SetIndexesRandom();
            Assert.AreNotEqual(l1.indexes[2], 2.0);
        }
        [TestMethod]
        public void TestOperator1()
        {
            LinearEquation l = new LinearEquation(array, 4);
            l = l + l;
            Assert.AreEqual(l.indexes[0], 2.0);
        }
        [TestMethod]
        public void TestOperator2()
        {
            LinearEquation l = new LinearEquation(array, 4);
            l = l - l;
            Assert.AreEqual(l.indexes[0], 0.0);
        }
        [TestMethod]
        public void TestOperator3()
        {
            LinearEquation l = new LinearEquation(array, 4);
            l = l * 2;
            Assert.AreEqual(l.indexes[0], 2.0);
        }
        [TestMethod]
        public void TestOperator4()
        {
            LinearEquation l = new LinearEquation(array, 4);
            l = 2 * l;
            Assert.AreEqual(l.indexes[0], 2.0);
        }
        [TestMethod]
        public void TestOperator5()
        {
            LinearEquation l = new LinearEquation(array, 4);
            Assert.AreEqual(l == l, true);
        }
        [TestMethod]
        public void TestOperator6()
        {
            LinearEquation l = new LinearEquation(array, 4);
            Assert.AreEqual(l != l, false);
        }
        [TestMethod]
        public void TestOperator7()
        {
            LinearEquation l = new LinearEquation(array, 4);
            LinearEquation l1 = new LinearEquation(4);
            Assert.AreEqual(l != l1, true);
        }
        [TestMethod]
        public void TestOperator10()
        {
            LinearEquation l = new LinearEquation(array, 4);
            Assert.AreEqual(-l.indexes[0], -1.0);
        }
        [TestMethod]
        public void FailWithWrongArguments1()
        {

            LinearEquation l1 = new LinearEquation(array, 4);
            LinearEquation l2 = new LinearEquation(10);
            Assert.ThrowsException<ArgumentException>(() => (l1 + l2));
        }
        [TestMethod]
        public void FailWithWrongArguments2()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            LinearEquation l2 = new LinearEquation(10);
            Assert.ThrowsException<ArgumentException>(() => (l1 - l2));
        }
        [TestMethod]
        public void FailWithWrongArguments3()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            LinearEquation l2 = new LinearEquation(10);
            Assert.ThrowsException<ArgumentException>(() => (l1 == l2));
        }
        [TestMethod]
        public void FailWithWrongArguments4()
        {
            LinearEquation l1 = new LinearEquation(array, 4);
            LinearEquation l2 = new LinearEquation(10);
            Assert.ThrowsException<ArgumentException>(() => (l1 == l2));
        }
        [TestMethod]
        public void TestSystem1()
        {
            LinearEquation l1 = new LinearEquation("2 4 1 36", 4);
            LinearEquation l2 = new LinearEquation("5 2 1 47", 4);
            LinearEquation l3 = new LinearEquation("2 3 4 37", 4);
            SystemOfLinearEquation slu = new SystemOfLinearEquation(3);
            slu[0] = l1;
            slu[1] = l2;
            slu[2] = l3;
            double[] x = slu.gauss();
            Assert.AreEqual(x[0], 7.0);
        }
        [TestMethod]
        public void FailWithWrongArguments5()
        {

            LinearEquation l1 = new LinearEquation("2 4 1 36", 4);
            LinearEquation l2 = new LinearEquation("5 2 1 47", 4);
            LinearEquation l3 = new LinearEquation(4);
            SystemOfLinearEquation slu = new SystemOfLinearEquation(3);
            slu[0] = l1;
            slu[1] = l2;
            slu[2] = l3;
            Assert.ThrowsException<ArgumentException>(() => slu.gauss());
        }
        [TestMethod]
        public void FailWithWrongArguments6()
        {
            LinearEquation l1 = new LinearEquation("2 4 1 36", 4);
            LinearEquation l2 = new LinearEquation("5 2 1 47", 4);
            LinearEquation l3 = new LinearEquation("0 0 0 1", 4);
            SystemOfLinearEquation slu = new SystemOfLinearEquation(3);
            slu[0] = l1;
            slu[1] = l2;
            slu[2] = l3;
            Assert.ThrowsException<ArgumentException>(() => slu.gauss());
        }
        [TestMethod]
        public void FailWithWrongArguments7()
        {
            LinearEquation l1 = new LinearEquation("2 4 1 36", 4);
            LinearEquation l2 = new LinearEquation("5 2 1 47", 4);
            LinearEquation l3 = new LinearEquation(4);
            SystemOfLinearEquation slu = new SystemOfLinearEquation(3);
            Assert.ThrowsException<IndexOutOfRangeException>(()=>slu[3]=l1);
        }
        [TestMethod]
        public void TestSystem2()
        {
            LinearEquation l1 = new LinearEquation(4);
            LinearEquation l2 = new LinearEquation(4);
            SystemOfLinearEquation slu = new SystemOfLinearEquation(3);
            slu[0] = l1;
            slu[1] = l2;
            Assert.AreEqual(slu[0].indexes[1], slu[1].indexes[3]);
        }
    }
}
