/* singleton: restricts instantiation of a class to one object */

#ifndef SINGLETON_T
#define SINGLETON_T

template <class T> class Singleton : public T {
 public:
	static T * Instance();

 protected:
	Singleton();
	~Singleton();

 private:
	static Singleton<T> * instance;
	class Cleaner {
	public:
		Cleaner();
		~Cleaner();
	};
	friend class Cleaner;
};

template <class T> Singleton<T> * Singleton<T>::instance = 0;

template <class T> T * Singleton<T>::Instance() {
	// static instance of Cleaner class assures singleton object is destructed
	static Cleaner cleanup;
	return (instance?instance:(instance = new Singleton<T>));
}

template <class T> Singleton<T>::Singleton() { }

template <class T> Singleton<T>::~Singleton() { }

template <class T> Singleton<T>::Cleaner::Cleaner() { }

template <class T> Singleton<T>::Cleaner::~Cleaner() {
	delete Singleton<T>::instance;
	Singleton<T>::instance = 0;
}

#endif
