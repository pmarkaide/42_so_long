/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map_is_valid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmarkaid <pmarkaid@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 16:50:37 by pmarkaid          #+#    #+#             */
/*   Updated: 2024/01/20 17:49:36 by pmarkaid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "unity/src/unity.h"
#include "../so_long.h"

int load_map(const char* map_file, t_data* data);

// Set up Unity test group
void setUp(void) {}

void tearDown(void) {}

// Write your test cases
void test_file_is_valid(void) {
    // Test your file_is_valid function
    // Use Unity assertion macros to check the expected behavior
    TEST_ASSERT_EQUAL_INT(0, file_is_valid("maps/valid_0.ber"));
    // Add more test cases as needed
}

void test_load_map(void) {
    // Test your load_map function
    TEST_ASSERT_EQUAL_INT(0, load_map("maps/valid_0.ber", NULL));
    // Add more test cases as needed
}

// Add more test functions for check_layout, check_chars, and check_path

// Entry point for running the tests
int main(void) {
    UNITY_BEGIN();

    // Run the tests
    RUN_TEST(test_file_is_valid);
    RUN_TEST(test_load_map);
    // Add more RUN_TEST for other functions

    return UNITY_END();
}