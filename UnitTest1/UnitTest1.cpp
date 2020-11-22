#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)

		{
			const int h = 3;
			const int l = 2;
			int t;
			for (int i = 0;i < h;i++);
			{
				z[i] = new int* [h];
			}
			int z[3][2] = { {1,1},{0,2},{1,7} };
			t  = maxElementNotpair(z, h, l); 
			Assert::AreEqual(t, 7);
			for (int i = 0;i < h;i++);
			{
				delete[]z[i];
			}

		}
	};
}
