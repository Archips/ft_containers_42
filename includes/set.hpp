#ifndef SET_HPP
# define SET_HPP

# include "enable_if.hpp"
# include "equal.hpp"
# include "is_integral.hpp"
# include "iterator_traits.hpp"
# include "make_pair.hpp"
# include "lexicographical_compare.hpp"
# include "pair.hpp"
# include "rbt_iterator_set.hpp"
# include "red_black_tree_set.hpp"
# include "reverse_iterator.hpp"

namespace ft {

	template < class Key, class Compare = std::less<Key>, class Alloc = std::allocator<Key> >
	class set {

    public:
        
		typedef Key 																key_type;
        typedef Key 																value_type;
        typedef Compare 															key_compare;
        typedef Compare 															value_compare;
        typedef Alloc																allocator_type;
        typedef typename Alloc::reference 											reference;
        typedef typename Alloc::const_reference										const_reference;
        typedef typename std::size_t												size_type;
        typedef typename std::ptrdiff_t												difference_type;
        typedef typename Alloc::pointer 											pointer;
        typedef typename Alloc::const_pointer 										const_pointer;
		typedef typename Alloc::template rebind<node<key_type> >::other				node_alloc;
		typedef node<key_type>														node_type;
		typedef node<key_type>*														node_ptr;
		typedef typename ft::rbt<key_type, key_compare>::iterator					iterator;
		typedef typename ft::rbt<key_type, key_compare>::const_iterator				const_iterator;
        typedef ft::reverse_iterator<iterator>			 							reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> 								const_reverse_iterator;

		private:

			size_type							_size;
			allocator_type						_alloc;
			key_compare							_key_comp;
			rbt<key_type, key_compare>			_rbt;

		public:

		/*
		 ** CONSTRUCTORS
		 */

        explicit set(const Compare& comp = Compare(), const Alloc& alloc = allocator_type()) :
			_size(0),
			_alloc(alloc), 
			_key_comp(comp) {}
        
		template <class InputIterator>
        set(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = allocator_type()) :
			_size(0), _alloc(alloc), _key_comp(comp)
		{
			for (; first != last; first++)
				this->insert(*first);
        }

		/*
		 ** COPY CONSTRUCTOR
		 */

		set(const set<Key, Compare, Alloc>& x) {

			*this = x;
		}
        
		/*
		 ** DESTRUCTOR
		 */

		~set() {

			this->clear();
		}

		/*
		 ** OPERATORS
		 */

        set<Key, Compare, Alloc>& operator= (const set<Key, Compare, Alloc>& x) {

			if (this != &x) {

				this->_size = x._size;
				this->_alloc = x._alloc;
				this->_comp = x._comp;
				this->_rbt.clear();
				insert(x.begin(), x.end());
			}
			return (*this);
		}

        
		/*
		 ** MEMBER FUNCTIONS
		 */

		allocator_type get_allocator() const {

			return (this->_alloc);
		}

		/* ITERATORS */

        iterator begin() {

			return (this->_rbt.begin());
		}

        const_iterator begin() const {

			return (this->_rbt.const_begin());
		}
        
		iterator end() {

			return (this->_rbt.end());
		}
        
		const_iterator end() const {

			return (this->_rbt.const_end());
		}
        
		reverse_iterator rbegin() {

			return (reverse_iterator(this->_rbt.end()));
		}
        
		const_reverse_iterator rbegin() const {

			return (const_reverse_iterator(this->_rbt.const_end()));
		}
        
		reverse_iterator rend() {

			return (reverse_iterator(this->_rbt.begin()));
		}
        
		const_reverse_iterator rend() const {

			return (const_reverse_iterator(this->_rbt.const_begin()));
		}
        
		/* CAPACITY */

		bool empty() const {

			return (this->_rbt.empty());
		}
        
		size_type size() const {

			return (this->_rbt.size());
		}
        
		size_type max_size() const {

			return (this->_rbt.max_size());
		}

		/* MODIFIERS */

        pair<iterator,bool> insert(const value_type& x) {

			return (this->_rbt.create_node(x));
		}
        
		iterator insert(iterator position, const value_type& x) {

			(void) position;
			return (this->insert(x));
		}
        
		template <class InputIterator>
        void insert(InputIterator first, InputIterator last) {

			for (; first != last; first ++)
				insert(*first);
		}
        
		void erase(iterator position) {

			this->erase(position);
		}
        
		size_type erase(const key_type& x) {

			return (this->_rbt.erase(x));
		}
        
		void erase(iterator first, iterator last) {

			iterator temp;

			for (; first != last; ) {

				temp = first;
				first ++;
				this->erase(temp);
			}
		}
        
		void swap(set<Key, Compare, Alloc>& x) {

			size_type						temp_size = this->_size;
			allocator_type					temp_alloc = this->_alloc;
			key_compare						temp_comp = this->_comp;

			this->_size = x._size;
			this->_alloc = x._alloc;
			this->_comp = x._comp;

			x._size = temp_size;
			x._alloc = temp_alloc;
			x._comp = temp_comp;
			this->_rbt.swap(x._rbt);
		}
        
		void clear() {

			this->_rbt.clear();
		}

		/* OBSERVERS */

		key_compare key_comp() const {

			return (this->_comp);
		}
        
		value_compare value_comp() const {

			return (value_compare(this->_comp));
		}
		
		/* OPERATIONS */
        
		iterator find(const key_type& k) const {

			node_ptr x = this->_rbt.root();

			while (x && x->data != x) {

				if (x && this->_rbt.value_compare(k, x->data))
					x = x->left_child;
				if (x && this->_rbt.value_compare(x->data, k))
					x = x->right_child;
			}
			if (!x)
				return (this->end());
			return (iterator(x, x->parent));
		}
     
		/* const_iterator find(const key_type& k) const { */

		/* 	node_ptr x = this->_rbt.root(); */

		/* 	while (x && x->data != x) { */

		/* 		if (x && this->_rbt.value_compare(k, x->data)) */
		/* 			x = x->left_child; */
		/* 		if (x && this->_rbt.value_compare(x->data, k)) */
		/* 			x = x->right_child; */
		/* 	} */
		/* 	if (!x) */
		/* 		return (this->end()); */
		/* 	return (const_iterator(x, x->parent)); */
		/* } */   

		size_type count(const key_type& k) const {
 
			node_ptr x = this->_rbt.root();

			while (x && x->data != x) {

				if (x && this->_rbt.value_compare(k, x->data))
					x = x->left_child;
				if (x && this->_rbt.value_compare(x->data, k))
					x = x->right_child;
			}
			if (!x)
				return (0);
			return (1);
		}       

		iterator lower_bound(const key_type& k) const {

			iterator it = this->begin();

			while (it != this->end()) {

				if (it >= k)
					break;
				it ++;
			}
			return (it);
		}
		
		/* const_iterator lower_bound(const key_type& k) const { */

		/* 	const_iterator it = this->begin(); */

		/* 	while (it != this->end()) { */
			
		/* 		if (it >= k) */
		/* 			break; */
		/* 		it ++; */
		/* 	} */
		/* 	return (it); */
		/* } */	
        
		iterator upper_bound(const key_type& k) const {

			iterator it = this->begin();

			while (it != this->end()) {

				if (it > k)
					break;
				it ++;
			}
			return (it);
		}
		
		/* const_iterator upper_bound(const key_type& k) const { */

		/* 	const_iterator it = this->begin(); */

		/* 	while (it != this->end()) { */

		/* 		if (it > k) */
		/* 			break; */
		/* 		it ++; */
		/* 	} */
		/* 	return (it); */
		/* } */
        
		pair<iterator, iterator> equal_range(const key_type& k) const {

			ft::pair<iterator, iterator> bound = ft::make_pair(this->lower_bound(k), this->upper_bound(k));
			return (bound);
		}

/* 		pair<const_iterator, const_iterator> equal_range(const key_type& k) const { */

/* 			ft::pair<const_iterator, const_iterator> bound = ft::make_pair(this->lower_bound(k), this->upper_bound(k)); */
/* 			return (bound); */
/* 		} */

	};
    
	/*
	 ** RELATIONAL OPERATORS
	 */ 

	template <class Key, class Compare, class Allocator>
    bool operator==(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	}
   
	template <class Key, class Compare, class Allocator>
    bool operator< (const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}
    
	template <class Key, class Compare, class Allocator>
    bool operator!=(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (!(lhs == rhs));
	}
    
	template <class Key, class Compare, class Allocator>
    bool operator> (const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (rhs < lhs);
	}
    
	template <class Key, class Compare, class Allocator>
    bool operator>=(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (!(lhs < rhs));
	}
    
	template <class Key, class Compare, class Allocator>
    bool operator<=(const set<Key,Compare,Allocator>& lhs, const set<Key,Compare,Allocator>& rhs) {

		return (!(rhs < lhs));
	}
    
	template <class Key, class Compare, class Allocator>
    void swap(set<Key, Compare, Allocator>& x, set<Key, Compare, Allocator>& y) {

		x.swap(y);
	}
}

#endif
