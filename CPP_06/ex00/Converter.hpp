#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <string>

class Converter
{
    private:
        std::string _str;
        int         _type;
        bool        _isValid;

        char        _cValue;
        int         _iValue;
        float       _fValue;
        double      _dValue;

        Converter();
        enum Type {
		    TypeChar,
		    TypeInt,
		    TypeFloat,
            TypeDouble,
		    TypeInvalid
	    };
        void      IsFormatValid();
        int         isOnlyOneDot();

    public:
        Converter(const std::string &value);
        Converter(const Converter &src);
        virtual ~Converter();
        Converter &operator=(const Converter &rhs);

        std::string     getStr()const;
        int             getType()const;
        void            setType(int type);

        void            findType();
  //      void            IsFormatValid();


};

std::ostream   &operator<<(std::ostream &os, const Converter &rhs);

#endif
