#include "unity.h"
#include "boundedQueue.h"

void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
}

void test_createQueue_validCapacity(void) {
    BoundedQueue *q = createQueue(5);
    TEST_ASSERT_NOT_NULL(q);
    TEST_ASSERT_EQUAL(0, q->size);
    TEST_ASSERT_EQUAL(5, q->capacity);
    free(q->elements); // Assuming you dynamically allocate elements
    free(q);
}

void test_enqueue_dequeue(void) {
    BoundedQueue *q = createQueue(2);
    enqueue(q, 1);
    TEST_ASSERT_EQUAL(1, q->size);
    enqueue(q, 2);
    TEST_ASSERT_EQUAL(2, q->size);

    TEST_ASSERT_EQUAL(1, dequeue(q));
    TEST_ASSERT_EQUAL(1, q->size);
    TEST_ASSERT_EQUAL(2, dequeue(q));
    TEST_ASSERT_EQUAL(0, q->size);

    free(q->elements);
    free(q);
}

void test_isFull_isEmpty(void) {
    BoundedQueue *q = createQueue(1);
    TEST_ASSERT_TRUE(isEmpty(q));
    TEST_ASSERT_FALSE(isFull(q));

    enqueue(q, 42);
    TEST_ASSERT_FALSE(isEmpty(q));
    TEST_ASSERT_TRUE(isFull(q));

    dequeue(q);
    TEST_ASSERT_TRUE(isEmpty(q));
    TEST_ASSERT_FALSE(isFull(q));

    free(q->elements);
    free(q);
}


int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [test_number]\n", argv[0]);
        return 1;
    }

    int test_number = atoi(argv[1]);

    UNITY_BEGIN();
    if (test_number == 1 || test_number == 0) RUN_TEST(test_createQueue_validCapacity);
    if (test_number == 2 || test_number == 0) RUN_TEST(test_enqueue_dequeue);
    if (test_number == 3 || test_number == 0) RUN_TEST(test_isFull_isEmpty);
    return UNITY_END();
}

