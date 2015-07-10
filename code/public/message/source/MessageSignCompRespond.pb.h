// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSignCompRespond.proto

#ifndef PROTOBUF_MessageSignCompRespond_2eproto__INCLUDED
#define PROTOBUF_MessageSignCompRespond_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace Message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageSignCompRespond_2eproto();
void protobuf_AssignDesc_MessageSignCompRespond_2eproto();
void protobuf_ShutdownFile_MessageSignCompRespond_2eproto();

class SignCompRespond;

// ===================================================================

class SignCompRespond : public ::google::protobuf::Message {
 public:
  SignCompRespond();
  virtual ~SignCompRespond();

  SignCompRespond(const SignCompRespond& from);

  inline SignCompRespond& operator=(const SignCompRespond& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const SignCompRespond& default_instance();

  void Swap(SignCompRespond* other);

  // implements Message ----------------------------------------------

  SignCompRespond* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SignCompRespond& from);
  void MergeFrom(const SignCompRespond& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bool btoday = 1;
  inline bool has_btoday() const;
  inline void clear_btoday();
  static const int kBtodayFieldNumber = 1;
  inline bool btoday() const;
  inline void set_btoday(bool value);

  // optional uint64 curtime = 2;
  inline bool has_curtime() const;
  inline void clear_curtime();
  static const int kCurtimeFieldNumber = 2;
  inline ::google::protobuf::uint64 curtime() const;
  inline void set_curtime(::google::protobuf::uint64 value);

  // optional int32 badagenum = 3;
  inline bool has_badagenum() const;
  inline void clear_badagenum();
  static const int kBadagenumFieldNumber = 3;
  inline ::google::protobuf::int32 badagenum() const;
  inline void set_badagenum(::google::protobuf::int32 value);

  // optional int32 getdays = 4;
  inline bool has_getdays() const;
  inline void clear_getdays();
  static const int kGetdaysFieldNumber = 4;
  inline ::google::protobuf::int32 getdays() const;
  inline void set_getdays(::google::protobuf::int32 value);

  // optional int32 continuedays = 5;
  inline bool has_continuedays() const;
  inline void clear_continuedays();
  static const int kContinuedaysFieldNumber = 5;
  inline ::google::protobuf::int32 continuedays() const;
  inline void set_continuedays(::google::protobuf::int32 value);

  // optional int32 totaldays = 6;
  inline bool has_totaldays() const;
  inline void clear_totaldays();
  static const int kTotaldaysFieldNumber = 6;
  inline ::google::protobuf::int32 totaldays() const;
  inline void set_totaldays(::google::protobuf::int32 value);

  // optional int32 gainnum = 7;
  inline bool has_gainnum() const;
  inline void clear_gainnum();
  static const int kGainnumFieldNumber = 7;
  inline ::google::protobuf::int32 gainnum() const;
  inline void set_gainnum(::google::protobuf::int32 value);

  // optional int32 extranum = 8;
  inline bool has_extranum() const;
  inline void clear_extranum();
  static const int kExtranumFieldNumber = 8;
  inline ::google::protobuf::int32 extranum() const;
  inline void set_extranum(::google::protobuf::int32 value);

  // repeated bool bsign = 9;
  inline int bsign_size() const;
  inline void clear_bsign();
  static const int kBsignFieldNumber = 9;
  inline bool bsign(int index) const;
  inline void set_bsign(int index, bool value);
  inline void add_bsign(bool value);
  inline const ::google::protobuf::RepeatedField< bool >&
      bsign() const;
  inline ::google::protobuf::RepeatedField< bool >*
      mutable_bsign();

  // optional int32 signcost = 10;
  inline bool has_signcost() const;
  inline void clear_signcost();
  static const int kSigncostFieldNumber = 10;
  inline ::google::protobuf::int32 signcost() const;
  inline void set_signcost(::google::protobuf::int32 value);

  // optional int32 freetimes = 11;
  inline bool has_freetimes() const;
  inline void clear_freetimes();
  static const int kFreetimesFieldNumber = 11;
  inline ::google::protobuf::int32 freetimes() const;
  inline void set_freetimes(::google::protobuf::int32 value);

  // optional int32 morrownum = 12;
  inline bool has_morrownum() const;
  inline void clear_morrownum();
  static const int kMorrownumFieldNumber = 12;
  inline ::google::protobuf::int32 morrownum() const;
  inline void set_morrownum(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Message.SignCompRespond)
 private:
  inline void set_has_btoday();
  inline void clear_has_btoday();
  inline void set_has_curtime();
  inline void clear_has_curtime();
  inline void set_has_badagenum();
  inline void clear_has_badagenum();
  inline void set_has_getdays();
  inline void clear_has_getdays();
  inline void set_has_continuedays();
  inline void clear_has_continuedays();
  inline void set_has_totaldays();
  inline void clear_has_totaldays();
  inline void set_has_gainnum();
  inline void clear_has_gainnum();
  inline void set_has_extranum();
  inline void clear_has_extranum();
  inline void set_has_signcost();
  inline void clear_has_signcost();
  inline void set_has_freetimes();
  inline void clear_has_freetimes();
  inline void set_has_morrownum();
  inline void clear_has_morrownum();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint64 curtime_;
  bool btoday_;
  ::google::protobuf::int32 badagenum_;
  ::google::protobuf::int32 getdays_;
  ::google::protobuf::int32 continuedays_;
  ::google::protobuf::int32 totaldays_;
  ::google::protobuf::int32 gainnum_;
  ::google::protobuf::RepeatedField< bool > bsign_;
  ::google::protobuf::int32 extranum_;
  ::google::protobuf::int32 signcost_;
  ::google::protobuf::int32 freetimes_;
  ::google::protobuf::int32 morrownum_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(12 + 31) / 32];

  friend void  protobuf_AddDesc_MessageSignCompRespond_2eproto();
  friend void protobuf_AssignDesc_MessageSignCompRespond_2eproto();
  friend void protobuf_ShutdownFile_MessageSignCompRespond_2eproto();

  void InitAsDefaultInstance();
  static SignCompRespond* default_instance_;
};
// ===================================================================


// ===================================================================

// SignCompRespond

// optional bool btoday = 1;
inline bool SignCompRespond::has_btoday() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SignCompRespond::set_has_btoday() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SignCompRespond::clear_has_btoday() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SignCompRespond::clear_btoday() {
  btoday_ = false;
  clear_has_btoday();
}
inline bool SignCompRespond::btoday() const {
  return btoday_;
}
inline void SignCompRespond::set_btoday(bool value) {
  set_has_btoday();
  btoday_ = value;
}

// optional uint64 curtime = 2;
inline bool SignCompRespond::has_curtime() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SignCompRespond::set_has_curtime() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SignCompRespond::clear_has_curtime() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SignCompRespond::clear_curtime() {
  curtime_ = GOOGLE_ULONGLONG(0);
  clear_has_curtime();
}
inline ::google::protobuf::uint64 SignCompRespond::curtime() const {
  return curtime_;
}
inline void SignCompRespond::set_curtime(::google::protobuf::uint64 value) {
  set_has_curtime();
  curtime_ = value;
}

// optional int32 badagenum = 3;
inline bool SignCompRespond::has_badagenum() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void SignCompRespond::set_has_badagenum() {
  _has_bits_[0] |= 0x00000004u;
}
inline void SignCompRespond::clear_has_badagenum() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void SignCompRespond::clear_badagenum() {
  badagenum_ = 0;
  clear_has_badagenum();
}
inline ::google::protobuf::int32 SignCompRespond::badagenum() const {
  return badagenum_;
}
inline void SignCompRespond::set_badagenum(::google::protobuf::int32 value) {
  set_has_badagenum();
  badagenum_ = value;
}

// optional int32 getdays = 4;
inline bool SignCompRespond::has_getdays() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void SignCompRespond::set_has_getdays() {
  _has_bits_[0] |= 0x00000008u;
}
inline void SignCompRespond::clear_has_getdays() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void SignCompRespond::clear_getdays() {
  getdays_ = 0;
  clear_has_getdays();
}
inline ::google::protobuf::int32 SignCompRespond::getdays() const {
  return getdays_;
}
inline void SignCompRespond::set_getdays(::google::protobuf::int32 value) {
  set_has_getdays();
  getdays_ = value;
}

// optional int32 continuedays = 5;
inline bool SignCompRespond::has_continuedays() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void SignCompRespond::set_has_continuedays() {
  _has_bits_[0] |= 0x00000010u;
}
inline void SignCompRespond::clear_has_continuedays() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void SignCompRespond::clear_continuedays() {
  continuedays_ = 0;
  clear_has_continuedays();
}
inline ::google::protobuf::int32 SignCompRespond::continuedays() const {
  return continuedays_;
}
inline void SignCompRespond::set_continuedays(::google::protobuf::int32 value) {
  set_has_continuedays();
  continuedays_ = value;
}

// optional int32 totaldays = 6;
inline bool SignCompRespond::has_totaldays() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void SignCompRespond::set_has_totaldays() {
  _has_bits_[0] |= 0x00000020u;
}
inline void SignCompRespond::clear_has_totaldays() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void SignCompRespond::clear_totaldays() {
  totaldays_ = 0;
  clear_has_totaldays();
}
inline ::google::protobuf::int32 SignCompRespond::totaldays() const {
  return totaldays_;
}
inline void SignCompRespond::set_totaldays(::google::protobuf::int32 value) {
  set_has_totaldays();
  totaldays_ = value;
}

// optional int32 gainnum = 7;
inline bool SignCompRespond::has_gainnum() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void SignCompRespond::set_has_gainnum() {
  _has_bits_[0] |= 0x00000040u;
}
inline void SignCompRespond::clear_has_gainnum() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void SignCompRespond::clear_gainnum() {
  gainnum_ = 0;
  clear_has_gainnum();
}
inline ::google::protobuf::int32 SignCompRespond::gainnum() const {
  return gainnum_;
}
inline void SignCompRespond::set_gainnum(::google::protobuf::int32 value) {
  set_has_gainnum();
  gainnum_ = value;
}

// optional int32 extranum = 8;
inline bool SignCompRespond::has_extranum() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void SignCompRespond::set_has_extranum() {
  _has_bits_[0] |= 0x00000080u;
}
inline void SignCompRespond::clear_has_extranum() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void SignCompRespond::clear_extranum() {
  extranum_ = 0;
  clear_has_extranum();
}
inline ::google::protobuf::int32 SignCompRespond::extranum() const {
  return extranum_;
}
inline void SignCompRespond::set_extranum(::google::protobuf::int32 value) {
  set_has_extranum();
  extranum_ = value;
}

// repeated bool bsign = 9;
inline int SignCompRespond::bsign_size() const {
  return bsign_.size();
}
inline void SignCompRespond::clear_bsign() {
  bsign_.Clear();
}
inline bool SignCompRespond::bsign(int index) const {
  return bsign_.Get(index);
}
inline void SignCompRespond::set_bsign(int index, bool value) {
  bsign_.Set(index, value);
}
inline void SignCompRespond::add_bsign(bool value) {
  bsign_.Add(value);
}
inline const ::google::protobuf::RepeatedField< bool >&
SignCompRespond::bsign() const {
  return bsign_;
}
inline ::google::protobuf::RepeatedField< bool >*
SignCompRespond::mutable_bsign() {
  return &bsign_;
}

// optional int32 signcost = 10;
inline bool SignCompRespond::has_signcost() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void SignCompRespond::set_has_signcost() {
  _has_bits_[0] |= 0x00000200u;
}
inline void SignCompRespond::clear_has_signcost() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void SignCompRespond::clear_signcost() {
  signcost_ = 0;
  clear_has_signcost();
}
inline ::google::protobuf::int32 SignCompRespond::signcost() const {
  return signcost_;
}
inline void SignCompRespond::set_signcost(::google::protobuf::int32 value) {
  set_has_signcost();
  signcost_ = value;
}

// optional int32 freetimes = 11;
inline bool SignCompRespond::has_freetimes() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void SignCompRespond::set_has_freetimes() {
  _has_bits_[0] |= 0x00000400u;
}
inline void SignCompRespond::clear_has_freetimes() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void SignCompRespond::clear_freetimes() {
  freetimes_ = 0;
  clear_has_freetimes();
}
inline ::google::protobuf::int32 SignCompRespond::freetimes() const {
  return freetimes_;
}
inline void SignCompRespond::set_freetimes(::google::protobuf::int32 value) {
  set_has_freetimes();
  freetimes_ = value;
}

// optional int32 morrownum = 12;
inline bool SignCompRespond::has_morrownum() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void SignCompRespond::set_has_morrownum() {
  _has_bits_[0] |= 0x00000800u;
}
inline void SignCompRespond::clear_has_morrownum() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void SignCompRespond::clear_morrownum() {
  morrownum_ = 0;
  clear_has_morrownum();
}
inline ::google::protobuf::int32 SignCompRespond::morrownum() const {
  return morrownum_;
}
inline void SignCompRespond::set_morrownum(::google::protobuf::int32 value) {
  set_has_morrownum();
  morrownum_ = value;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_MessageSignCompRespond_2eproto__INCLUDED
