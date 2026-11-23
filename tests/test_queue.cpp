#include <gtest/gtest.h>
#include <stdexcept>
#include <string>
#include <utility>
#include "tqueue.h"

using namespace std;

TEST(Queue, can_create_queue_with_positive_capacity) {
	ASSERT_NO_THROW(Queue<int> q(5));
}

TEST(Queue, default_capacity_is_one) {
	Queue<int> q;
	EXPECT_EQ(1u, q.capacity());
}

TEST(Queue, cant_create_queue_with_zero_capacity) {
	ASSERT_THROW(Queue<int> q(0), invalid_argument);
}

TEST(Queue, new_queue_is_empty) {
	Queue<int> q(3);
	EXPECT_TRUE(q.IsEmpty());
	EXPECT_EQ(0u, q.size());
}


TEST(Queue, queue_with_element_is_not_empty) {
	Queue<int> q(3);
	q.push(1);
	EXPECT_FALSE(q.IsEmpty());
	EXPECT_EQ(1u, q.size());
}

TEST(Queue, queue_is_full_after_capacity_pushes) {
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.push(3);
	EXPECT_TRUE(q.IsFull());
	EXPECT_EQ(3u, q.size());
}

TEST(Queue, get_returns_first_pushed_element) {
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	EXPECT_EQ(1, q.get());
}

TEST(Queue, pop_removes_first_element) {
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	q.pop();
	EXPECT_EQ(2, q.get());
	EXPECT_EQ(1u, q.size());
}

TEST(Queue, queue_becomes_empty_after_popping_all) {
	Queue<int> q(2);
	q.push(1);
	q.push(2);
	q.pop();
	q.pop();
	EXPECT_TRUE(q.IsEmpty());
}

TEST(Queue, elements_come_out_in_fifo_order) {
	Queue<int> q(4);
	for (int i = 1; i <= 4; ++i) q.push(i);
	for (int i = 1; i <= 4; ++i) {
		EXPECT_EQ(i, q.get());
		q.pop();
	}
}

TEST(Queue, cant_push_to_full_queue) {
	Queue<int> q(2);
	q.push(1);
	q.push(2);
	ASSERT_THROW(q.push(3), overflow_error);
}

TEST(Queue, failed_push_does_not_change_queue) {
	Queue<int> q(2);
	q.push(1);
	q.push(2);
	try { q.push(3); } catch (const overflow_error&) {}
	EXPECT_EQ(2u, q.size());
	EXPECT_EQ(1, q.get());
}

TEST(Queue, cant_pop_from_empty_queue) {
	Queue<int> q(2);
	ASSERT_THROW(q.pop(), underflow_error);
}

TEST(Queue, cant_get_from_empty_queue) {
	Queue<int> q(2);
	ASSERT_THROW(q.get(), underflow_error);
}

TEST(Queue, can_copy_queue) {
	Queue<int> q(3);
	q.push(1);
	ASSERT_NO_THROW(Queue<int> copy(q));
}

TEST(Queue, copied_queue_has_same_content) {
	Queue<int> q(3);
	q.push(1);
	q.push(2);
	Queue<int> copy(q);
	EXPECT_EQ(q.size(), copy.size());
	EXPECT_EQ(q.capacity(), copy.capacity());
	EXPECT_EQ(1, copy.get()); copy.pop();
	EXPECT_EQ(2, copy.get());
}

TEST(Queue, copied_queue_has_its_own_memory) {
	Queue<int> q(3);
	q.push(1);
	Queue<int> copy(q);
	copy.pop();
	copy.push(100);
	EXPECT_EQ(1, q.get());
	EXPECT_EQ(1u, q.size());
}

TEST(Queue, can_assign_queue) {
	Queue<int> a(3), b(5);
	a.push(1); a.push(2);
	b.push(7);
	b = a;
	EXPECT_EQ(3u, b.capacity());
	EXPECT_EQ(2u, b.size());
	EXPECT_EQ(1, b.get()); b.pop();
	EXPECT_EQ(2, b.get());
}
