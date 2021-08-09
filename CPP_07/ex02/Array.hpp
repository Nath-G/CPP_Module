#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{   
    private:
        unsigned int    _n;
        T               *_array;

    public:
        Array(): _n(0), _array(NULL) {}
        Array(unsigned int n):  _n(n), _array(new T[n]) {}
        Array(Array const &src):  _n(0), _array(NULL) { 
            *this = src;
            }
        ~Array() { if (_n > 0) delete[] _array; }

        Array  &operator=(const Array &rhs) {
            if (this == &rhs)
                return (*this);
            delete[] _array;
		    _array = new T[rhs.size()];
		    _n = rhs.size();
		    for (unsigned int i = 0; i < _n; i++)
			    _array[i] = rhs._array[i];
		    return (*this);
        }

	class			OutOfLimitsException : public std::exception {
		public:
			const char	*what() const throw() {
				return ("Value out of Limits");
			};
	};
        
	T				&operator[](unsigned int index) const {
		if (index < 0 || index >= _n)
			throw OutOfLimitsException();
		return(_array[index]);
	}
    unsigned int	size() const { return (this->_n); }
};

#endif
