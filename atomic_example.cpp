// addMoney.cpp

#include <functional>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

std::mutex mut;

struct Account{
    int balance{100};                             
};

void addMoney(Account& to, int amount){
    mut.lock();
  to.balance += amount;                         
  mut.unlock();
}

int main(){
  
  std::cout << std::endl;

  Account account;
  
  std::vector<std::thread> vecThreads(100);
  
                                                 
  for (auto& thr: vecThreads) thr = std::thread(addMoney, std::ref(account), 49);
  
  for (auto& thr: vecThreads) thr.join();
  
                                                 
  std::cout << "account.balance: " << account.balance << std::endl;
  
  std::cout << std::endl;

}