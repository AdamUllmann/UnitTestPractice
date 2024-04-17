/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}
TEST(PasswordTest, single_letter_password_lowercase)
{
        Password my_password;
        int actual = my_password.count_leading_characters("z");
        ASSERT_EQ(1, actual);
}
TEST(PasswordTest, multiletter_password)
{
        Password my_password;
        int actual = my_password.count_leading_characters("ZZ");
        ASSERT_EQ(2, actual);
}
TEST(PasswordTest, mismatching_characters)
{
        Password my_password;
        int actual = my_password.count_leading_characters("AB");
        ASSERT_EQ(1, actual);
}
TEST(PasswordTest, large_password_size)
{
        Password my_password;
        int actual = my_password.count_leading_characters("abcdefghijklmnopqrstuvwxyz");
        ASSERT_EQ(1, actual);
}
TEST(PasswordTest, large_password_size_with_matching_leading_characters)
{
        Password my_password;
        int actual = my_password.count_leading_characters("aaaaaaafghijklmnopqrstuvwxyz");
        ASSERT_EQ(7, actual);
}
TEST(PasswordTest, differing_cases)
{
        Password my_password;
        int actual = my_password.count_leading_characters("aAaA");
        ASSERT_EQ(1, actual);
}



TEST(PasswordTest, differing_cases_for_new_test)
{
        Password my_password;
	string str = "aAaA";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(1, actual);
}

TEST(PasswordTest, matching_cases_for_new_test)
{
        Password my_password;
	string str = "aaaa";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(0, actual);
}

TEST(PasswordTest, alphabet)
{
        Password my_password;
        string str = "abcdefghijklmnopqrtuvwxyz";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(0, actual);
}

TEST(PasswordTest, alphabet_with_outlier)
{
        Password my_password;
        string str = "abcdefgHijklm";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(1, actual);
}

TEST(PasswordTest, final_letter_caps)
{
        Password my_password;
        string str = "abcsefG";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(1, actual);
}

TEST(PasswordTest, long_string)
{
        Password my_password;
        string str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(0, actual);
}

TEST(PasswordTest, all_caps)
{
        Password my_password;
        string str = "ABCDEFG";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(0, actual);
}

TEST(PasswordTest, final_lowercase)
{
        Password my_password;
        string str = "ABCDEFg";
        int actual = my_password.has_mixed_case(str);
        ASSERT_EQ(1, actual);
}
