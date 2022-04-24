#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

class linkedList {

public:
  struct Node {
    std::string data;
    Node *next_ptr;
  };

private:
  // 単方向リストの宣言
  Node *node;

public:
  // 実体を持たないので nullptr で初期化
  linkedList() { node = nullptr; }

  ~linkedList() {}

  void appendElement(std::string data);
  void insertElement(std::string data);
  void deleteElement(std::string data);
  void displayList();
};

/*************************************
void appendElement(std::string data)
リストの最後に要素を追加する
1. 新しい要素を作成する
2. リストの最後に新しい要素を追加する
  - リストが空のとき
    - 新しい要素のポインタをセットする
  - そうでないとき
    - リストの最後までループする
    - 新しいノードを最後のノードの参照としてセットする
*************************************/
void linkedList::appendElement(std::string data) {
  Node *findNode = node;
  // 新しいノード
  Node newNode = {data, nullptr};

  // 先頭の要素が nullptr ならば先頭に挿入
  if (node == nullptr) {
    std::cout << "先頭に要素を設定します" << std::endl;
    // 先頭のアドレスに
    node = &newNode;
    std::cout << node->data << std::endl;
  } else {
    // node->next == nullptr を調べるために全探索
    while (1) {
      // 次のポインタが nullptr ならばノードを挿入
      if (findNode->next_ptr == nullptr) {
        std::cout << "要素を挿入します" << std::endl;
        findNode->next_ptr = &newNode;
        // 次のノードに移動して追加した値を表示
        findNode = findNode->next_ptr;
        std::cout << "追加した値 = " << findNode->data << std::endl;
        return;
      }
      // node
      findNode = findNode->next_ptr;
    }
  }
}

void linkedList::insertElement(std::string) {}
void linkedList::deleteElement(std::string) {}

/*************************************
void linkedList::displayList() const
*************************************/
void linkedList::displayList() {
  //  Node *headNode = node;
  //    node = node->next_ptr;
  std::cout << node->data << std::endl;
}

int main() {
  linkedList lists;
  lists.appendElement("test");
  lists.appendElement("hoge");
  lists.appendElement("fuga");
  lists.appendElement("hogefuga");
  //  lists.displayList();
  std::cout << "実行終了" << std::endl;
}
