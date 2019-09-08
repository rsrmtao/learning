#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double random(int min, int max)
{
    double rand_num;
    rand_num = rand() / (double)(RAND_MAX) * (max - min) + min;
    return rand_num;
}

void random_arr(double arr[], int len, int min, int max)
{
    time_t t;
    srand(time(&t));
    for (int i = 0; i < len; i++)
    {
        arr[i] = random(min, max);
        // printf("%f\n", arr[i]);
    }
}

/*
冒泡排序：从小到大排序，每次比较相邻两个元素，若左边元素大于右边元素，
则交换这个两个元素的位置。故每一轮次比较，能够保证最后一个元素为最大值。
*/
void bubble_sort(double arr[], int len)
{
    double temp;
    for (int i = len - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

/*
选择排序：每次找到当前最小值，在未排序序列中找到最小（大）元素，存放到
排序序列的起始位置，然后，再从剩余未排序元素中继续寻找最小（大）元素，
然后放到已排序序列的末尾。
*/
void select_sort(double arr[], int len)
{
    double temp;
    int min;
    for (int i = 0; i < len; i++)
    {
        min = i;
        for (int j = i; j < len; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

/*
双向选择排序：对未排序序列同时选择最小值和最大值
*/
void bi_select_sort(double arr[], int len)
{
    double temp;
    int min, max;
    for (int i = 0; i < len; i++)
    {
        min = i, max = len - 1 - i;
        for (int j = i; j < len - i; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            if (arr[j] > arr[max])
            {
                max = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
        temp = arr[len - 1 - i];
        arr[len - 1 - i] = arr[max];
        arr[max] = temp;
    }
}


/*
测试不同排序算法的计算时间
*/
void test_sort_algo()
{
    time_t start_time, end_time;
    double cost_time;
    

    // 生成随机序列，用于排序
    srand(time(NULL));
    int len = 10000;
    printf("随机数组长度：%d\n", len);
    double arr[len];
    random_arr(arr, len, 0, 10);

    start_time = clock();
    // sort 
    bubble_sort(arr, len);
    // for (int i = 0; i < len; i++)
    //     printf("%f ", arr[i]);

    end_time = clock();
    printf("---------------------\n");
    cost_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; //change to seconds
    printf("bubble_sort cost time: %f \n", cost_time);

    random_arr(arr, len, 0, 10);
    start_time = clock();
    // sort 
    select_sort(arr, len);
    // for (int i = 0; i < len; i++)
    //     printf("%f ", arr[i]);

    end_time = clock();
    printf("---------------------\n");
    cost_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; //change to seconds
    printf("select_sort cost time: %f \n", cost_time);

    random_arr(arr, len, 0, 10);
    start_time = clock();
    // sort 
    bi_select_sort(arr, len);
    // for (int i = 0; i < len; i++)
    //     printf("%f ", arr[i]);

    end_time = clock();
    printf("---------------------\n");
    cost_time = (double)(end_time - start_time) / CLOCKS_PER_SEC; //change to seconds
    printf("bi_select_sort cost time: %f \n", cost_time);
}

int main()
{
    test_sort_algo();
    // printf("%f\n", random(2,5));
}
