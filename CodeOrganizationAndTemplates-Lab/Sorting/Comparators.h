#ifndef Comparators_h
#define Comparators_h

template<typename T> class LessThan {
    public:
        bool operator()( const T & left, const T& right ) const {
            return left < right;
        }
};

template<typename T, typename Comparator>
class Reverse {
    public:
        bool operator()( const T & left, const T& right ) const {
            Comparator comparator;
            return !comparator(left, right);
        }
};

#endif
