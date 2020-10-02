#include <deque>
#include <iostream>
#include <set>
#include <vector>


inline auto factorize(int num){
  std::vector<int> factors;
  for(int div = 2; div <= num; ++div){
    //std::cout<<"div = "<<div<<"  num = "<<num<<"  num mod div = "<<num%div<<"  num/div = "<<num/div<<std::endl;
    if(num==1){ 
      break;
    }else if(num%div == 0){
      factors.push_back(div);
      num /= div;
      --div;
    }else if(div > num / 2){
      factors.push_back(num);
      break;
    }
  }
  return factors;
}

//same as above, but ordered via multiset
inline auto sfactorize(int num){
  std::multiset<int> factors;
  for(int div = 2; div <= num; ++div){
    //std::cout<<"div = "<<div<<"  num = "<<num<<"  num mod div = "<<num%div<<"  num/div = "<<num/div<<std::endl;
    if(num==1){ 
      break;
    }else if(num%div == 0){
      factors.insert(div);
      num /= div;
      --div;
    }else if(div > num / 2){
      factors.insert(num);
      break;
    }
  }
  return factors;
}

//same as above, but ordered via multiset and output via dequeue
inline auto defactorize(int num){
  std::multiset<int> factors;
  for(int div = 2; div <= num; ++div){
    //std::cout<<"div = "<<div<<"  num = "<<num<<"  num mod div = "<<num%div<<"  num/div = "<<num/div<<std::endl;
    if(num==1){ 
      break;
    }else if(num%div == 0){
      factors.insert(div);
      num /= div;
      --div;
    }else if(div > num / 2){
      factors.insert(num);
      break;
    }
  }

  std::deque<int> defactors;
  for(auto& p:factors){
    defactors.push_back(p);
  }
  return defactors;
}

int main(int argc, char** argv){

  int kmin=2;
  int kmax=16;

  for(int k=kmin; k<kmax; ++k){
    auto prime_factors = factorize(k);

    std::cout<<"Prime factors of "<<k<<" are: ";
    for(auto& p : prime_factors){
      std::cout<<p<<"  ";
    }
    std::cout<<std::endl;
  }
  
  std::cout<<std::endl;
  std::cout<<std::endl;

  for(int k=kmin; k<kmax; ++k){
    auto prime_factors = sfactorize(k);

    std::cout<<"Prime factors of "<<k<<" are: ";
    for(auto& p : prime_factors){
      std::cout<<p<<"  ";
    }
    std::cout<<std::endl;
  }
  
  std::cout<<std::endl;
  std::cout<<std::endl;

  for(int k=kmin; k<kmax; ++k){
    auto prime_factors = defactorize(k);

    std::cout<<"Prime factors of "<<k<<" are: ";
    for(auto& p : prime_factors){
      std::cout<<p<<"  ";
    }
    std::cout<<std::endl;
  }
  
  return 0;
}
