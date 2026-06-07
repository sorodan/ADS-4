// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                count = count + 1;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            int sum = arr[i] + arr[j];

            if (sum > value) {
                break;
            }

            if (sum == value) {
                count=count + 1;
            }
        }
    }

    return count;
}

int countPairs3search(int* arr, int left, int right, int target) {
    while (left <= right) {
        int midNum = left + (right - left) / 2;

        if (arr[midNum] == target)
            return midNum;
        if (arr[midNum] < target)
            left = midNum + 1;
        else
            right = midNum - 1;
    }
    return -1;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len - 1; i++) {
        int Num = value - arr[i];

        int indNum = countPairs3search(arr, i + 1, len - 1, Num);

        if (indNum != -1) {
            int leftNum = indNum;
            int rightNum = indNum;

            while (leftNum - 1 > i && arr[leftNum - 1] == Num)
                leftNum = leftNum - 1;

            while (rightNum + 1 < len && arr[rightNum + 1] == Num)
               rightNum = rightNum + 1;

            count += (rightNum - leftNum + 1);
        }
    }
    return count;
}
