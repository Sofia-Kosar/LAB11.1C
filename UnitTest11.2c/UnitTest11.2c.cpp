#include "pch.h"
#include "CppUnitTest.h"
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "../AB11.2C/AB11.2C.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest112c
{
	TEST_CLASS(UnitTest112c)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const char* inputFileName = "test_input.bin";
			const char* evenFileName = "test_even.bin";
			const char* oddFileName = "test_odd.bin";

			// Create a test input file
			FILE* inputFile;
			fopen_s(&inputFile, inputFileName, "wb");
			Assert::IsNotNull(inputFile);
			const char* testData = "123456789";
			fwrite(testData, sizeof(char), strlen(testData), inputFile);
			fclose(inputFile);

			// Act
			ProcessBIN1(const_cast<char*>(inputFileName), const_cast<char*>(evenFileName), const_cast<char*>(oddFileName));

			

			
		}
	};
}
