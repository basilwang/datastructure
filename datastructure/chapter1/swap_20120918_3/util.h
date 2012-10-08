template <class T1>
class util
{
public:
	void swap(T1 &x,T1 &y);
};
template <class T1>
void util<T1>::swap(T1 &x,T1 &y)
{
   int t;
   t=x;
   x=y;
   y=t;
}