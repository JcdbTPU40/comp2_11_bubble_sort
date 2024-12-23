#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// バブルソート(引数が不適切であればfalseを返す)
bool bubble_sort(item* begin, const item* end)
{
    if (begin == NULL || end == NULL) {
        return false;
    }

    if (end <= begin) {
        return false;
    }

    const size_t size = end - begin;
    if (size < 2) {
        return true;
    }

    for (size_t i = 0; i < size - 1; i++) {
        bool swapped = false;
        for (size_t j = 0; j < size - 1 - i; j++) {
            if (begin[j].key > begin[j + 1].key) {

                item temp = begin[j];
                begin[j] = begin[j + 1];
                begin[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return true;
}
