#include "ex12.19.h"

StrBlobPtr StrBlob::begin() {
    return StrBlobPtr(*this);
}

StrBlobPtr StrBlob::end() {
    return StrBlobPtr(*this, data->size());
}

ConstStrBlobPtr StrBlob::begin() const {
    return ConstStrBlobPtr(*this);
}

ConstStrBlobPtr StrBlob::end() const {
    return ConstStrBlobPtr(*this, data->size());
}
