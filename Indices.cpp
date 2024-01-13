#include<iostream>
#include<unordered_map>

int* finder(int* arr, int count, int target) {
    std::unordered_map<int,int> map;
    static int ret[2];
    for(int i = 0; i < count; ++i) {
        if(map.count(target - arr[i])) {
            ret[0] = map[target - arr[i]];
            ret[1] = i;
            return ret;
        }
        
        map[arr[i]] = i;
    }
    return ret;
}


int main() {
    int test1[] = {2, 7, 11, 15};
    int count = sizeof(test1) / sizeof(*test1);
    int target = 9;
    int *indices = finder(test1, count, target);
    std::cout << "[" << indices[0] << "," << indices[1] << "]" << std::endl;
    
    int test2[] = {3, 2, 4};
    count = sizeof(test2) / sizeof(*test2);
    target = 6;
    indices = finder(test2, count, target);
    std::cout << "[" << indices[0] << "," << indices[1] << "]" << std::endl;
    
    int test3[] = {3, 3};
    count = sizeof(test3) / sizeof(*test3);
    target = 6;
    indices = finder(test3, count, target);
    std::cout << "[" << indices[0] << "," << indices[1] << "]" << std::endl;
    
    return 0;
}
