/**
 * Unit Tests for Field class
**/

#include <gtest/gtest.h>
#include <iostream>
#include "Field.h"
 
class FieldTest : public ::testing::Test
{
	protected:
		FieldTest(){}
		virtual ~FieldTest(){}
		virtual void SetUp(){}
		virtual void TearDown(){}
};

TEST(FieldTest, placeMineInBounds)
{
	Field minefield;
	
	minefield.placeMine(4,5);
	ASSERT_EQ( MINE_HIDDEN, minefield.get(4,5) );
}

TEST(FieldTest, placeMineOutBounds)
{
	Field minefield;
	minefield.placeMine(200, 111);
        ASSERT_EQ( MINE_HIDDEN, minefield.get(200,111) );
}

TEST(FieldTest, Safe)
{
	Field minefield;
	minefield.placeMine(1,1);
	ASSERT_TRUE(minefield.isSafe(2,2));

}

TEST(FieldTest, NotSafe)
{
        Field minefield;
        minefield.placeMine(1,1);
        ASSERT_FALSE(minefield.isSafe(1,1));
}

TEST(FieldTest, getOutBounds)
{
	Field minefield;
	ASSERT_ANY_THROW(minefield.get(111,122));
} 
