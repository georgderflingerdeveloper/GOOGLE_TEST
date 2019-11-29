#include "pch.h"
#include "../ODROID/Analyzing.h"
#include "../ODROID/Analyzing.cpp"

constexpr int ANY_INVALID_ADC_VALUE      = 9999;
constexpr int INVALID_ADC_VALUE          = 1024;
constexpr int VALID_ADC_VALUE            = 729;
constexpr int NEGATIVE_INVALID_ADC_VALUE = -1024;

namespace Testing
{

	TEST(TestCaseRawValue, Test_Verify_Raw_ValueIsZero) {

		int TestRawValueFromADC = 0;
		int CheckedValue = ANY_INVALID_ADC_VALUE;

		Analyzer SignalAnalyzer;
		SignalAnalyzer.VerifyRawValue(TestRawValueFromADC, CheckedValue);

		EXPECT_EQ(CheckedValue, TestRawValueFromADC);
	}

	TEST(TestCaseRawValue, Test_Verify_Raw_ValueWasValid_Gets_Invalid) {

		Analyzer SignalAnalyzer;
		int TestRawValueFromADC = VALID_ADC_VALUE;
		int CheckedValue        = ANY_INVALID_ADC_VALUE;

		SignalAnalyzer.VerifyRawValue(TestRawValueFromADC, CheckedValue);

		TestRawValueFromADC = INVALID_ADC_VALUE;
		SignalAnalyzer.VerifyRawValue(TestRawValueFromADC, CheckedValue);

		EXPECT_EQ(CheckedValue, VALID_ADC_VALUE);
	}

	TEST(TestCaseRawValue, Test_Verify_Raw_ValueWasValid_Gets_Invalid_With_Negative_Value) {

		Analyzer SignalAnalyzer;
		int TestRawValueFromADC = VALID_ADC_VALUE;
		int CheckedValue        = ANY_INVALID_ADC_VALUE;

		SignalAnalyzer.VerifyRawValue(TestRawValueFromADC, CheckedValue);

		TestRawValueFromADC = NEGATIVE_INVALID_ADC_VALUE;
		SignalAnalyzer.VerifyRawValue(TestRawValueFromADC, CheckedValue);

		EXPECT_EQ(CheckedValue, VALID_ADC_VALUE);
	}
}
