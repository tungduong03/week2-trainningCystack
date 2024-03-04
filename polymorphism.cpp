#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

//tạo struct double linked list
struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{

   protected:
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

//class LRUCache kế thừa từ Cache
class LRUCache: public Cache{
    public:

        //khởi tạo độ lớn của cache
        LRUCache(int cp) {
            this->cp = cp;
        }

        void set(int k, int v) {
            Node* N;

            //nếu cache (list) chưa có phần tử nào thì thêm vào 1 phần tử
            if ( mp.empty() ) {

                N = new Node(k,v);
                //đầu và cuối đều trỏ đến node N
                tail = head = N;
                mp[k] = N;
            }

            //tìm vị trí trong vector mp
            auto it = mp.find(k);

            //nếu tìm thấy
            if ( it != mp.end() ) {

                //set value là value mới
                it->second->value = v;

                if ( head == it->second ) { //nếu đó là phần tử đầu tiên rồi thì ko làm gì cả
                    return;
                }


                it->second->prev->next = it->second->next; //nếu không phải //nối node trước trỏ đến node liền sau


                if ( tail == it->second ) { //nếu nó là phần tử cuối

                    tail = tail->prev; //gắn phần tử cuối là phần tử trước đó
                }
                else {
                    //nếu không phải phần tử cuối thì gán prev phần tử sau là phần tử liền trước
                    it->second->next->prev = it->second->prev;
                }

                //đưa node đó lên head
                it->second->next = head;
                it->second->prev = nullptr;
                head->prev = it->second;
                head = it->second;
            }
            //không tìm thấy phần tử trong cache
            else {
                //tạo node mới, head sẽ trỏ đến node mới này
                N = new Node(head->prev, head, k, v);
                head->prev = N;
                head = N;
                mp[k] = N;

                //nếu số phần tử cache > cp thì xóa node cuối
                if ( mp.size() > cp ) {
                    tail = tail->prev;
                    mp.erase(tail->next->key);
                    cout<<" sadsa "<<tail->next->value<<endl;
                    delete tail->next;
                    cout<<" sadsa "<<tail->next->value<<endl;
                    tail->next = nullptr;
                }
            }
        }
        int get(int k) {

            //nếu tìm thấy key
            auto it = mp.find(k);
            if ( it != mp.end() ) {
                return it->second->value;
            }
            //nếu ko tìm thấy
            return -1;
        }
};
int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      }
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}

