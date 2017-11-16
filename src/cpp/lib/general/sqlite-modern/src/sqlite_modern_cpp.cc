#include "general/sqlite-modern/sqlite_modern_cpp.h"
#include <ctime>
namespace sqlite{

// int
template<> database_binder&& operator <<(database_binder&& db,int const&& val) {
	int hresult;
	if((hresult = sqlite3_bind_int(db._stmt, db._inx, val)) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}
	++db._inx;
	return std::move(db);
}
template<> void get_col_from_db(database_binder& db, int inx, int& val) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		val = 0;
	} else {
		val = sqlite3_column_int(db._stmt, inx);
	}
}

// sqlite_int64
template<> database_binder&& operator <<(database_binder&& db, sqlite_int64 const&& val) {
	int hresult;
	if((hresult = sqlite3_bind_int64(db._stmt, db._inx, val)) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}

	++db._inx;
	return std::move(db);
}
template<> void get_col_from_db(database_binder& db,int inx, sqlite3_int64& i) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		i = 0;
	} else {
		i = sqlite3_column_int64(db._stmt, inx);
	}
}

// float
template<> database_binder&& operator <<(database_binder&& db,float const&& val) {
	int hresult;
	if((hresult = sqlite3_bind_double(db._stmt, db._inx, double(val))) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}

	++db._inx;
	return std::move(db);
}
template<> void get_col_from_db(database_binder& db, int inx, float& f) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		f = 0;
	} else {
		f = float(sqlite3_column_double(db._stmt, inx));
	}
}

// double
template<> database_binder&& operator <<(database_binder&& db,double const&& val) {
	int hresult;
	if((hresult = sqlite3_bind_double(db._stmt, db._inx, val)) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}

	++db._inx;
	return std::move(db);
}
template<> void get_col_from_db(database_binder& db, int inx, double& d) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		d = 0;
	} else {
		d = sqlite3_column_double(db._stmt, inx);
	}
}

// std::string
template<> void get_col_from_db(database_binder& db, int inx,std::string & s) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		s = std::string();
	} else {
		sqlite3_column_bytes(db._stmt, inx);
		s = std::string((char*)sqlite3_column_text(db._stmt, inx));
	}
}
template<> database_binder&& operator <<(database_binder&& db, std::string const&& txt) {
	int hresult;
	if((hresult = sqlite3_bind_text(db._stmt, db._inx, txt.data(), -1, SQLITE_TRANSIENT)) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}

	++db._inx;
	return std::move(db);
}
// std::u16string
template<> void get_col_from_db(database_binder& db, int inx, std::u16string & w) {
	if(sqlite3_column_type(db._stmt, inx) == SQLITE_NULL) {
		w = std::u16string();
	} else {
		sqlite3_column_bytes16(db._stmt, inx);
		w = std::u16string((char16_t *)sqlite3_column_text16(db._stmt, inx));
	}
}
template<> database_binder&& operator <<(database_binder&& db, std::u16string const&& txt) {
	int hresult;
	if((hresult = sqlite3_bind_text16(db._stmt, db._inx, txt.data(), -1, SQLITE_TRANSIENT)) != SQLITE_OK) {
		db.throw_sqlite_error(hresult);
	}

	++db._inx;
	return std::move(db);
}
}
