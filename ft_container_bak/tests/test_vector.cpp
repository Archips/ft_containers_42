#include "../vector.hpp"
#include <iostream>

int main(void)
{

	/*
	 ** COPY CONSTRUCTOR
	 */

	{	  

		ft::vector<int> v1(4, 300);
		v1[3] = 200;
		ft::vector<int> v2(v1);

		std::cout << ">>>> V1 <<<<" << std::endl;
		std::cout << "Size : " << v1.size() << std::endl;
		std::cout << "Capacity : " << v1.capacity() << std::endl;
		std::cout << "Begin : " << v1.begin() << std::endl;
		std::cout << "End : " << v1.end() << std::endl;
		std::cout << "Back : " << v1.front() << std::endl;
		std::cout << "Front : " << v1.back() << std::endl;
		std::cout << "V1 : ";
		ft::vector<int>::iterator it = v1.begin();
		for (; it != v1.end(); ++it)
			std::cout << " " << *it;

		std::cout << ">>>> V2 <<<<" << std::endl;
		std::cout << "Size : " << v2.size() << std::endl;
		std::cout << "Capacity : " << v2.capacity() << std::endl;
		std::cout << "Begin : " << v2.begin() << std::endl;
		std::cout << "End : " << v2.end() << std::endl;
		std::cout << "Front : " << v2.front() << std::endl;
		std::cout << "Back : " << v2.back() << std::endl;
		std::cout << "V2 : ";
		it = v2.begin();
		for (; it != v2.end(); ++it)
			std::cout << " " << *it;
	}

	/* { */
    /*     ft::vector<int> first; */
    /*     ft::vector<int> copy(first); */
    /*     ft::vector<int> op; */
    /*     ft::vector<int> second(4, 100); */
    /*     ft::vector<int> third(second); */
    /*     op = copy; */

    /*     std::cout << "First size : " << first.size() << std::endl; */
    /*     std::cout << "Is first empty ? " << first.empty() << std::endl; */

    /*     second[2] = 300; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << second[i] << std::endl; */

    /*     std::cout << "Second size : " << second.size() << std::endl; */
    /*     std::cout << "Is second empty ? " << second.empty() << std::endl; */

    /*     copy = second; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << copy[i] << std::endl; */

    /*     for (int i = 0; i < 4; i++) */
    /*         std::cout << third[i] << std::endl; */
    /* } */

    /* { */
    /*     ft::vector<int> myvector(100, 100); */

    /*     std::cout << "Size: " << (int) myvector.size() << std::endl; */
    /*     std::cout << "Capacity: " << myvector.capacity() << std::endl; */
    /*     std::cout << "Max size: " << myvector.max_size() << std::endl; */

    /* } */

	/* { */

	/*  	ft::vector<int> myvector (10);   // 10 zero-initialized ints */

  		/* // assign some values: */
  		
	/* 	for (unsigned i=0; i<myvector.size(); i++) */
   			/* myvector.at(i)=i; */

	/* 	std::cout << "myvector contains:"; */
	/* 	for (unsigned i=0; i<myvector.size(); i++) */
	/* 		std::cout << ' ' << myvector.at(i); */
  		/* std::cout << std::endl; */

	/* 	std::cout << "First of myvector is: " << myvector.front() << std::endl; */
	/* 	std::cout << "Last of myvector is: " << myvector.back() << std::endl; */
	/* 	std::cout << "Size of myvector is: " << myvector.size() << std::endl; */
	/* 	myvector.pop_back(); */
	/* 	std::cout << "Last of myvector is: " << myvector.back() << std::endl; */
	/* 	std::cout << "Size of myvector is: " << myvector.size() << std::endl; */
		
	/* 	myvector.clear(); */

	/* 	for (unsigned i=0; i<myvector.size(); i++) */
   			/* myvector.at(i)=i; */
	/* 	std::cout << "-------------------------------" << std::endl; */
	/* 	std::cout << "First of myvector is: " << myvector.front() << std::endl; */
	/* 	std::cout << "Last of myvector is: " << myvector.back() << std::endl; */
	/* 	std::cout << "Size of myvector is: " << myvector.size() << std::endl; */
	/* 	std::cout << "-------------------------------" << std::endl; */

	/* 	std::cout << "End of scope" << std::endl; */
	/* } */

	/* { */
	/* 	ft::vector<int> vectoooor; */
	/* } */

	/* { */
	/* 	ft::vector<int> myvector(5); */
	/* 	myvector[0] = 1; */ 
	/* 	myvector[1] = 2; */
	/* 	myvector[2] = 3; */
	/* 	myvector[3] = 0; */
	/* 	myvector[4] = 0; */

	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */

	/* 	std::cout << std::endl; */

	/* 	std::cout << "my vector capacity : " << myvector.capacity() << std::endl; */

	/* 	myvector.resize(2); */

	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */
	
	/* 	std::cout << std::endl; */

	/* 	std::cout << "my vector capacity : " << myvector.capacity() << std::endl; */

	/* 	myvector.resize(5); */

	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */

	/* 	std::cout << std::endl; */
		
	/* 	std::cout << "my vector capacity : " << myvector.capacity() << std::endl; */
		
	/* 	myvector.resize(7, 10); */

	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */
		
	/* 	std::cout << std::endl; */

	/* 	std::cout << "my vector capacity : " << myvector.capacity() << std::endl; */
		
	/* 	std::cout << std::endl; */

	/* 	myvector.resize(3); */
	/* 	myvector.push_back(-8); */

	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */
		
	/* 	std::cout << std::endl; */


	/* 	std::cout << "Last of myvector is: " << myvector.back() << std::endl; */

	/* 	std::cout << "Size of myvector is: " << myvector.size() << std::endl; */

	/* 	std::cout << "Capacity of myvector is: " << myvector.capacity() << std::endl; */
	/* } */

	/* { */
	/* 	ft::vector<int> myvector; */
  		/* int myint; */

  		/* std::cout << "Please enter some integers (enter 0 to end):\n"; */

  		/* do { */
    		/* std::cin >> myint; */
    		/* myvector.push_back (myint); */
  		/* } while (myint); */

  		/* std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n"; */
	/* 	std::cout << "Last of myvector is: " << myvector.back() << std::endl; */
	/* 	for (unsigned i = 0; i < myvector.size(); i ++) */
	/* 		std::cout << ' ' << myvector.at(i); */
	/* 	std::cout << std::endl; */	
		
	/* } */	

/* 	{ */

/* 		ft::vector<int> myvector; */
/*   		for (int i=0; i<10; i++) myvector.push_back(i); */

/*   		typedef ft::vector<int>::iterator iter_type; */
/*                                                          	// ? 0 1 2 3 4 5 6 7 8 9 ? */
/*   		iter_type from (myvector.begin());               	//   ^ */
/*                                                          	//         ------> */
/*   		iter_type until (myvector.end());               	//                       ^ */
/*                                                          	// */
/*   		ft::reverse_iterator<iter_type> rev_until (from);  // ^ */
/*                                                          	//         <------ */
/*   		ft::reverse_iterator<iter_type> rev_from (until);  //                     ^ */

/* 		std::cout << "From: " << *from << std::endl; */
/* 		std::cout << "Until: " << *until << std::endl; */

/* 		std::cout << "Rev_until: " << *rev_until << std::endl; */
/* 		std::cout << "Rev_from: " << *rev_from << std::endl; */

/*   		std::cout << "myvector:"; */
/*   		while (rev_from != rev_until) */
/* 		{ */
/* 			std::cout << ' ' << *rev_from++; */
/* 		} */
/* 		std::cout << '\n'; */
		
/* 		std::cout << "vector -> "; */
/* 		iter_type it = myvector.begin(); */
/* 		for (; it != myvector.end(); ++it) */
/* 			std::cout << ' ' << *it; */
/* 		std::cout << std::endl; */

/* 	} */	

/* 	{ */
	
/* 		ft::vector<int> foo (3,100);   // three ints with a value of 100 */
/*   		ft::vector<int> bar (2,200);   // two ints with a value of 200 */
/* 		ft::vector<int> baz (3,100); */

/* 		if (foo==bar) std::cout << "foo and bar are equal\n"; */
/*   		if (foo!=bar) std::cout << "foo and bar are not equal\n"; */
/*   		if (foo< bar) std::cout << "foo is less than bar\n"; */
/*   		if (foo> bar) std::cout << "foo is greater than bar\n"; */
/*   		if (foo<=bar) std::cout << "foo is less than or equal to bar\n"; */
/*   		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n"; */

/* 		if (foo==baz) std::cout << "foo and baz are equal\n"; */
/*   		if (foo!=baz) std::cout << "foo and baz are not equal\n"; */
/*   		if (foo< baz) std::cout << "foo is less than baz\n"; */
/*   		if (foo> baz) std::cout << "foo is greater than baz\n"; */
/*   		if (foo<=baz) std::cout << "foo is less than or equal to baz\n"; */
/*   		if (foo>=baz) std::cout << "foo is greater than or equal to baz\n"; */

/* 	} */

/* 	{ */

/* 		ft::vector<int> a(3, 100); */
/* 		ft::vector<int> b(2, 200); */

/* 		std::cout << "a -> "; */
/* 		ft::vector<int>::iterator it = a.begin(); */
/* 		for (; it != a.end(); ++it) */
/* 			std::cout << ' ' << *it; */
/* 		std::cout << std::endl; */

/* 		std::cout << "b -> "; */
/* 		it = b.begin(); */
/* 		for (; it != b.end(); ++it) */
/* 			std::cout << ' ' << *it; */
/* 		std::cout << std::endl; */

/* 		ft::swap(a, b); */

/* 		std::cout << "a -> "; */
/* 		it = a.begin(); */
/* 		for (; it != a.end(); ++it) */
/* 			std::cout << ' ' << *it; */
/* 		std::cout << std::endl; */

/* 		std::cout << "b -> "; */
/* 		it = b.begin(); */
/* 		for (; it != b.end(); ++it) */
/* 			std::cout << ' ' << *it; */
/* 		std::cout << std::endl; */

/* 	} */	

	return (0);
}