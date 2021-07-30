#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <limits.h>
# include <cstdlib>
# include <iomanip>
# include <cmath>


class Converter
{
    private:
        std::string     _str;
        int             _type;
        char            _cValue;
        int             _iValue;
        float           _fValue;
        double          _dValue;

        Converter();

        void            findType();
        void            convert();
        void            convert(char c);
        void            convert(int i);
        void            convert(float f);
        void            convert(double d);
        void            check_validity();
        bool floatIsValue(void) const;
        bool doubleIsValue(void) const;
    public:
        Converter(const std::string &value);
        Converter(const Converter &src);
        virtual ~Converter();
        Converter &operator=(const Converter &rhs);
    
            enum Type {
		    TypeChar,
		    TypeInt,
		    TypeFloat,
            TypeDouble,
		    TypeInvalid
	    };
        enum Status {
            Valid,
            Undisplayable,
            Impossible
        };
    
        int             _status[4];
        static std::string _stat[3];

    
        std::string     getStr()const;
        int             getType()const;
        void            setType(int type);
        char            getCvalue()const;
        void            setCvalue(char c);
        int             getIvalue()const;
        void            setIvalue(int i);
        float           getFvalue()const;
        void            setFvalue(float f);
        double          getDvalue()const;
        void            setDvalue(double d);
    //    int             getStatus()const;
    //    void            setStatus(int status);


   //    void            initConverter(int type)const;


};

std::ostream   &operator<<(std::ostream &os, const Converter &rhs);

#endif
