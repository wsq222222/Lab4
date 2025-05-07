#include <iostream>
#include <memory>
#include <string>

class Inventory {
private:
    std::unique_ptr<std::string[]> itemList;
    size_t maxItems;
    size_t currentCount;

public:
    Inventory(size_t max = 10)
        : maxItems(max), currentCount(0), itemList(std::make_unique<std::string[]>(max)) {
    }

    void addItem(const std::string& itemName) {
        if (currentCount < maxItems) {
            itemList[currentCount++] = itemName;
        }
        else {
            std::cout << "No more space in inventory!\n";
        }
    }

    void showItems() const {
        std::cout << "Current Inventory:\n";
        for (size_t i = 0; i < currentCount; ++i) {
            std::cout << "- " << itemList[i] << '\n';
        }
    }
};

int main() {
    Inventory bag(8);
    bag.addItem("AK47");
    bag.addItem("M4A1");
    bag.addItem("NEGEV");

    bag.showItems();

    return 0;
}