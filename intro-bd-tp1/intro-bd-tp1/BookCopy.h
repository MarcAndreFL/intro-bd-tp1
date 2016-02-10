

class BookCopy{
	private:
		unsigned int _copyNo;
		unsigned int _iSBN;
		bool _available;

	public:
		BookCopy(unsigned int copyNo, unsigned int isbn, bool available){
			_copyNo = copyNo;
			_iSBN = isbn;
			_available = available;
		}
		//Getters
		unsigned int GetCopyNo(){ return _copyNo; };
		unsigned int GetISBN(){ return _iSBN; };
		bool GetAvailable(){ return _available; };

		//Setters
		void SetAvailable(bool available){ _available = available; };

};