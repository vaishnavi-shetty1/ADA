#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
 int profit;
 int weight;
 float profitRatio;
 float fraction;
};
bool compareItems(Item a, Item b) {
 return a.profitRatio > b.profitRatio;
}
void fractionalKnapsack(vector<Item> &items, int knCap) {
 float remCap = knCap, totProfit = 0.0;
 for (auto &item : items) {
 if (item.weight <= remCap) {
 item.fraction = 1.0;
 remCap -= item.weight;
 totProfit += item.profit;
 } else {
 item.fraction = remCap / item.weight;
 totProfit += item.profit * item.fraction;
 break;
 }
 }
 cout << "\nFractional Knapsack Solution:\n";
 cout << "Item\tWeight\tProfit\tFraction Chosen\n";
 for (size_t i = 0; i < items.size(); i++) {
 cout << i + 1 << "\t" << items[i].weight << "\t" << items[i].profit << "\t" << 
items[i].fraction << endl;
}
 cout << "\nTotal Profit (Fractional): " << totProfit << endl;
}
void zeroOneKnapsack(vector<Item> &items, int knCap) {
 int remCap = knCap, totProfit = 0;
 for (auto &item : items) {
 if (item.weight <= remCap) {
 item.fraction = 1.0; 
 remCap -= item.weight;
 totProfit += item.profit;
 } else {
 item.fraction = 0.0; 
 }
 }
 cout << "\n0/1 Knapsack Solution (Greedy, may be suboptimal):\n";
 cout << "Item\tWeight\tProfit\tTaken(1=Yes, 0=No)\n";
 for (size_t i = 0; i < items.size(); i++) {
 cout << i + 1 << "\t" << items[i].weight << "\t" << items[i].profit << "\t" << 
(items[i].fraction == 1.0 ? "1" : "0") << endl;
 }
 cout << "\nTotal Profit (0/1 Greedy): " << totProfit << endl;
}
int main() {
 int iNum, knCap;
 vector<Item> items;
 cout << "Enter the number of items: ";
 cin >> iNum;
 cout << "Enter Knapsack capacity: ";
 cin >> knCap;
 
 for (int i = 0; i < iNum; i++) {
 Item item;
 cout << "Enter profit: ";
 cin >> item.profit;
 cout << "Enter weight: ";
 cin >> item.weight;
 item.profitRatio = (float)item.profit / item.weight;
 item.fraction = 0.0f;
 items.push_back(item);
 }
sort(items.begin(), items.end(), compareItems);
 fractionalKnapsack(items, knCap);
 zeroOneKnapsack(items, knCap);
 return 0;
}