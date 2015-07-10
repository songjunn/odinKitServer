// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageBattleJoinerNotify.proto

#ifndef PROTOBUF_MessageBattleJoinerNotify_2eproto__INCLUDED
#define PROTOBUF_MessageBattleJoinerNotify_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageBattleJoinerNotify_2eproto();
void protobuf_AssignDesc_MessageBattleJoinerNotify_2eproto();
void protobuf_ShutdownFile_MessageBattleJoinerNotify_2eproto();

class BattleJoinerNotify;

// ===================================================================

class BattleJoinerNotify : public ::google::protobuf::Message {
 public:
  BattleJoinerNotify();
  virtual ~BattleJoinerNotify();

  BattleJoinerNotify(const BattleJoinerNotify& from);

  inline BattleJoinerNotify& operator=(const BattleJoinerNotify& from) {
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
  static const BattleJoinerNotify& default_instance();

  void Swap(BattleJoinerNotify* other);

  // implements Message ----------------------------------------------

  BattleJoinerNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BattleJoinerNotify& from);
  void MergeFrom(const BattleJoinerNotify& from);
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

  // optional int64 jid = 1;
  inline bool has_jid() const;
  inline void clear_jid();
  static const int kJidFieldNumber = 1;
  inline ::google::protobuf::int64 jid() const;
  inline void set_jid(::google::protobuf::int64 value);

  // optional string jname = 2;
  inline bool has_jname() const;
  inline void clear_jname();
  static const int kJnameFieldNumber = 2;
  inline const ::std::string& jname() const;
  inline void set_jname(const ::std::string& value);
  inline void set_jname(const char* value);
  inline void set_jname(const char* value, size_t size);
  inline ::std::string* mutable_jname();
  inline ::std::string* release_jname();
  inline void set_allocated_jname(::std::string* jname);

  // optional int32 jwpid = 3;
  inline bool has_jwpid() const;
  inline void clear_jwpid();
  static const int kJwpidFieldNumber = 3;
  inline ::google::protobuf::int32 jwpid() const;
  inline void set_jwpid(::google::protobuf::int32 value);

  // optional int32 jcamp = 4;
  inline bool has_jcamp() const;
  inline void clear_jcamp();
  static const int kJcampFieldNumber = 4;
  inline ::google::protobuf::int32 jcamp() const;
  inline void set_jcamp(::google::protobuf::int32 value);

  // optional int32 jmerit = 5;
  inline bool has_jmerit() const;
  inline void clear_jmerit();
  static const int kJmeritFieldNumber = 5;
  inline ::google::protobuf::int32 jmerit() const;
  inline void set_jmerit(::google::protobuf::int32 value);

  // optional int32 jranking = 6;
  inline bool has_jranking() const;
  inline void clear_jranking();
  static const int kJrankingFieldNumber = 6;
  inline ::google::protobuf::int32 jranking() const;
  inline void set_jranking(::google::protobuf::int32 value);

  // optional int32 jaction = 7;
  inline bool has_jaction() const;
  inline void clear_jaction();
  static const int kJactionFieldNumber = 7;
  inline ::google::protobuf::int32 jaction() const;
  inline void set_jaction(::google::protobuf::int32 value);

  // optional int32 jbuyact = 8;
  inline bool has_jbuyact() const;
  inline void clear_jbuyact();
  static const int kJbuyactFieldNumber = 8;
  inline ::google::protobuf::int32 jbuyact() const;
  inline void set_jbuyact(::google::protobuf::int32 value);

  // optional int64 jacttime = 9;
  inline bool has_jacttime() const;
  inline void clear_jacttime();
  static const int kJacttimeFieldNumber = 9;
  inline ::google::protobuf::int64 jacttime() const;
  inline void set_jacttime(::google::protobuf::int64 value);

  // optional int64 jactcdtime = 10;
  inline bool has_jactcdtime() const;
  inline void clear_jactcdtime();
  static const int kJactcdtimeFieldNumber = 10;
  inline ::google::protobuf::int64 jactcdtime() const;
  inline void set_jactcdtime(::google::protobuf::int64 value);

  // optional int32 jrewarddialy = 11;
  inline bool has_jrewarddialy() const;
  inline void clear_jrewarddialy();
  static const int kJrewarddialyFieldNumber = 11;
  inline ::google::protobuf::int32 jrewarddialy() const;
  inline void set_jrewarddialy(::google::protobuf::int32 value);

  // optional int32 jdoublewin = 12;
  inline bool has_jdoublewin() const;
  inline void clear_jdoublewin();
  static const int kJdoublewinFieldNumber = 12;
  inline ::google::protobuf::int32 jdoublewin() const;
  inline void set_jdoublewin(::google::protobuf::int32 value);

  // optional int32 jcurrentwin = 13;
  inline bool has_jcurrentwin() const;
  inline void clear_jcurrentwin();
  static const int kJcurrentwinFieldNumber = 13;
  inline ::google::protobuf::int32 jcurrentwin() const;
  inline void set_jcurrentwin(::google::protobuf::int32 value);

  // optional int32 jOwnwps = 14;
  inline bool has_jownwps() const;
  inline void clear_jownwps();
  static const int kJOwnwpsFieldNumber = 14;
  inline ::google::protobuf::int32 jownwps() const;
  inline void set_jownwps(::google::protobuf::int32 value);

  // optional int32 jOwnSpecialwps = 15;
  inline bool has_jownspecialwps() const;
  inline void clear_jownspecialwps();
  static const int kJOwnSpecialwpsFieldNumber = 15;
  inline ::google::protobuf::int32 jownspecialwps() const;
  inline void set_jownspecialwps(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Message.BattleJoinerNotify)
 private:
  inline void set_has_jid();
  inline void clear_has_jid();
  inline void set_has_jname();
  inline void clear_has_jname();
  inline void set_has_jwpid();
  inline void clear_has_jwpid();
  inline void set_has_jcamp();
  inline void clear_has_jcamp();
  inline void set_has_jmerit();
  inline void clear_has_jmerit();
  inline void set_has_jranking();
  inline void clear_has_jranking();
  inline void set_has_jaction();
  inline void clear_has_jaction();
  inline void set_has_jbuyact();
  inline void clear_has_jbuyact();
  inline void set_has_jacttime();
  inline void clear_has_jacttime();
  inline void set_has_jactcdtime();
  inline void clear_has_jactcdtime();
  inline void set_has_jrewarddialy();
  inline void clear_has_jrewarddialy();
  inline void set_has_jdoublewin();
  inline void clear_has_jdoublewin();
  inline void set_has_jcurrentwin();
  inline void clear_has_jcurrentwin();
  inline void set_has_jownwps();
  inline void clear_has_jownwps();
  inline void set_has_jownspecialwps();
  inline void clear_has_jownspecialwps();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 jid_;
  ::std::string* jname_;
  ::google::protobuf::int32 jwpid_;
  ::google::protobuf::int32 jcamp_;
  ::google::protobuf::int32 jmerit_;
  ::google::protobuf::int32 jranking_;
  ::google::protobuf::int32 jaction_;
  ::google::protobuf::int32 jbuyact_;
  ::google::protobuf::int64 jacttime_;
  ::google::protobuf::int64 jactcdtime_;
  ::google::protobuf::int32 jrewarddialy_;
  ::google::protobuf::int32 jdoublewin_;
  ::google::protobuf::int32 jcurrentwin_;
  ::google::protobuf::int32 jownwps_;
  ::google::protobuf::int32 jownspecialwps_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(15 + 31) / 32];

  friend void  protobuf_AddDesc_MessageBattleJoinerNotify_2eproto();
  friend void protobuf_AssignDesc_MessageBattleJoinerNotify_2eproto();
  friend void protobuf_ShutdownFile_MessageBattleJoinerNotify_2eproto();

  void InitAsDefaultInstance();
  static BattleJoinerNotify* default_instance_;
};
// ===================================================================


// ===================================================================

// BattleJoinerNotify

// optional int64 jid = 1;
inline bool BattleJoinerNotify::has_jid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void BattleJoinerNotify::set_has_jid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void BattleJoinerNotify::clear_has_jid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void BattleJoinerNotify::clear_jid() {
  jid_ = GOOGLE_LONGLONG(0);
  clear_has_jid();
}
inline ::google::protobuf::int64 BattleJoinerNotify::jid() const {
  return jid_;
}
inline void BattleJoinerNotify::set_jid(::google::protobuf::int64 value) {
  set_has_jid();
  jid_ = value;
}

// optional string jname = 2;
inline bool BattleJoinerNotify::has_jname() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void BattleJoinerNotify::set_has_jname() {
  _has_bits_[0] |= 0x00000002u;
}
inline void BattleJoinerNotify::clear_has_jname() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void BattleJoinerNotify::clear_jname() {
  if (jname_ != &::google::protobuf::internal::kEmptyString) {
    jname_->clear();
  }
  clear_has_jname();
}
inline const ::std::string& BattleJoinerNotify::jname() const {
  return *jname_;
}
inline void BattleJoinerNotify::set_jname(const ::std::string& value) {
  set_has_jname();
  if (jname_ == &::google::protobuf::internal::kEmptyString) {
    jname_ = new ::std::string;
  }
  jname_->assign(value);
}
inline void BattleJoinerNotify::set_jname(const char* value) {
  set_has_jname();
  if (jname_ == &::google::protobuf::internal::kEmptyString) {
    jname_ = new ::std::string;
  }
  jname_->assign(value);
}
inline void BattleJoinerNotify::set_jname(const char* value, size_t size) {
  set_has_jname();
  if (jname_ == &::google::protobuf::internal::kEmptyString) {
    jname_ = new ::std::string;
  }
  jname_->assign(reinterpret_cast<const char*>(value), size);
}
inline ::std::string* BattleJoinerNotify::mutable_jname() {
  set_has_jname();
  if (jname_ == &::google::protobuf::internal::kEmptyString) {
    jname_ = new ::std::string;
  }
  return jname_;
}
inline ::std::string* BattleJoinerNotify::release_jname() {
  clear_has_jname();
  if (jname_ == &::google::protobuf::internal::kEmptyString) {
    return NULL;
  } else {
    ::std::string* temp = jname_;
    jname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
    return temp;
  }
}
inline void BattleJoinerNotify::set_allocated_jname(::std::string* jname) {
  if (jname_ != &::google::protobuf::internal::kEmptyString) {
    delete jname_;
  }
  if (jname) {
    set_has_jname();
    jname_ = jname;
  } else {
    clear_has_jname();
    jname_ = const_cast< ::std::string*>(&::google::protobuf::internal::kEmptyString);
  }
}

// optional int32 jwpid = 3;
inline bool BattleJoinerNotify::has_jwpid() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void BattleJoinerNotify::set_has_jwpid() {
  _has_bits_[0] |= 0x00000004u;
}
inline void BattleJoinerNotify::clear_has_jwpid() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void BattleJoinerNotify::clear_jwpid() {
  jwpid_ = 0;
  clear_has_jwpid();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jwpid() const {
  return jwpid_;
}
inline void BattleJoinerNotify::set_jwpid(::google::protobuf::int32 value) {
  set_has_jwpid();
  jwpid_ = value;
}

// optional int32 jcamp = 4;
inline bool BattleJoinerNotify::has_jcamp() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void BattleJoinerNotify::set_has_jcamp() {
  _has_bits_[0] |= 0x00000008u;
}
inline void BattleJoinerNotify::clear_has_jcamp() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void BattleJoinerNotify::clear_jcamp() {
  jcamp_ = 0;
  clear_has_jcamp();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jcamp() const {
  return jcamp_;
}
inline void BattleJoinerNotify::set_jcamp(::google::protobuf::int32 value) {
  set_has_jcamp();
  jcamp_ = value;
}

// optional int32 jmerit = 5;
inline bool BattleJoinerNotify::has_jmerit() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void BattleJoinerNotify::set_has_jmerit() {
  _has_bits_[0] |= 0x00000010u;
}
inline void BattleJoinerNotify::clear_has_jmerit() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void BattleJoinerNotify::clear_jmerit() {
  jmerit_ = 0;
  clear_has_jmerit();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jmerit() const {
  return jmerit_;
}
inline void BattleJoinerNotify::set_jmerit(::google::protobuf::int32 value) {
  set_has_jmerit();
  jmerit_ = value;
}

// optional int32 jranking = 6;
inline bool BattleJoinerNotify::has_jranking() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void BattleJoinerNotify::set_has_jranking() {
  _has_bits_[0] |= 0x00000020u;
}
inline void BattleJoinerNotify::clear_has_jranking() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void BattleJoinerNotify::clear_jranking() {
  jranking_ = 0;
  clear_has_jranking();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jranking() const {
  return jranking_;
}
inline void BattleJoinerNotify::set_jranking(::google::protobuf::int32 value) {
  set_has_jranking();
  jranking_ = value;
}

// optional int32 jaction = 7;
inline bool BattleJoinerNotify::has_jaction() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void BattleJoinerNotify::set_has_jaction() {
  _has_bits_[0] |= 0x00000040u;
}
inline void BattleJoinerNotify::clear_has_jaction() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void BattleJoinerNotify::clear_jaction() {
  jaction_ = 0;
  clear_has_jaction();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jaction() const {
  return jaction_;
}
inline void BattleJoinerNotify::set_jaction(::google::protobuf::int32 value) {
  set_has_jaction();
  jaction_ = value;
}

// optional int32 jbuyact = 8;
inline bool BattleJoinerNotify::has_jbuyact() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void BattleJoinerNotify::set_has_jbuyact() {
  _has_bits_[0] |= 0x00000080u;
}
inline void BattleJoinerNotify::clear_has_jbuyact() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void BattleJoinerNotify::clear_jbuyact() {
  jbuyact_ = 0;
  clear_has_jbuyact();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jbuyact() const {
  return jbuyact_;
}
inline void BattleJoinerNotify::set_jbuyact(::google::protobuf::int32 value) {
  set_has_jbuyact();
  jbuyact_ = value;
}

// optional int64 jacttime = 9;
inline bool BattleJoinerNotify::has_jacttime() const {
  return (_has_bits_[0] & 0x00000100u) != 0;
}
inline void BattleJoinerNotify::set_has_jacttime() {
  _has_bits_[0] |= 0x00000100u;
}
inline void BattleJoinerNotify::clear_has_jacttime() {
  _has_bits_[0] &= ~0x00000100u;
}
inline void BattleJoinerNotify::clear_jacttime() {
  jacttime_ = GOOGLE_LONGLONG(0);
  clear_has_jacttime();
}
inline ::google::protobuf::int64 BattleJoinerNotify::jacttime() const {
  return jacttime_;
}
inline void BattleJoinerNotify::set_jacttime(::google::protobuf::int64 value) {
  set_has_jacttime();
  jacttime_ = value;
}

// optional int64 jactcdtime = 10;
inline bool BattleJoinerNotify::has_jactcdtime() const {
  return (_has_bits_[0] & 0x00000200u) != 0;
}
inline void BattleJoinerNotify::set_has_jactcdtime() {
  _has_bits_[0] |= 0x00000200u;
}
inline void BattleJoinerNotify::clear_has_jactcdtime() {
  _has_bits_[0] &= ~0x00000200u;
}
inline void BattleJoinerNotify::clear_jactcdtime() {
  jactcdtime_ = GOOGLE_LONGLONG(0);
  clear_has_jactcdtime();
}
inline ::google::protobuf::int64 BattleJoinerNotify::jactcdtime() const {
  return jactcdtime_;
}
inline void BattleJoinerNotify::set_jactcdtime(::google::protobuf::int64 value) {
  set_has_jactcdtime();
  jactcdtime_ = value;
}

// optional int32 jrewarddialy = 11;
inline bool BattleJoinerNotify::has_jrewarddialy() const {
  return (_has_bits_[0] & 0x00000400u) != 0;
}
inline void BattleJoinerNotify::set_has_jrewarddialy() {
  _has_bits_[0] |= 0x00000400u;
}
inline void BattleJoinerNotify::clear_has_jrewarddialy() {
  _has_bits_[0] &= ~0x00000400u;
}
inline void BattleJoinerNotify::clear_jrewarddialy() {
  jrewarddialy_ = 0;
  clear_has_jrewarddialy();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jrewarddialy() const {
  return jrewarddialy_;
}
inline void BattleJoinerNotify::set_jrewarddialy(::google::protobuf::int32 value) {
  set_has_jrewarddialy();
  jrewarddialy_ = value;
}

// optional int32 jdoublewin = 12;
inline bool BattleJoinerNotify::has_jdoublewin() const {
  return (_has_bits_[0] & 0x00000800u) != 0;
}
inline void BattleJoinerNotify::set_has_jdoublewin() {
  _has_bits_[0] |= 0x00000800u;
}
inline void BattleJoinerNotify::clear_has_jdoublewin() {
  _has_bits_[0] &= ~0x00000800u;
}
inline void BattleJoinerNotify::clear_jdoublewin() {
  jdoublewin_ = 0;
  clear_has_jdoublewin();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jdoublewin() const {
  return jdoublewin_;
}
inline void BattleJoinerNotify::set_jdoublewin(::google::protobuf::int32 value) {
  set_has_jdoublewin();
  jdoublewin_ = value;
}

// optional int32 jcurrentwin = 13;
inline bool BattleJoinerNotify::has_jcurrentwin() const {
  return (_has_bits_[0] & 0x00001000u) != 0;
}
inline void BattleJoinerNotify::set_has_jcurrentwin() {
  _has_bits_[0] |= 0x00001000u;
}
inline void BattleJoinerNotify::clear_has_jcurrentwin() {
  _has_bits_[0] &= ~0x00001000u;
}
inline void BattleJoinerNotify::clear_jcurrentwin() {
  jcurrentwin_ = 0;
  clear_has_jcurrentwin();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jcurrentwin() const {
  return jcurrentwin_;
}
inline void BattleJoinerNotify::set_jcurrentwin(::google::protobuf::int32 value) {
  set_has_jcurrentwin();
  jcurrentwin_ = value;
}

// optional int32 jOwnwps = 14;
inline bool BattleJoinerNotify::has_jownwps() const {
  return (_has_bits_[0] & 0x00002000u) != 0;
}
inline void BattleJoinerNotify::set_has_jownwps() {
  _has_bits_[0] |= 0x00002000u;
}
inline void BattleJoinerNotify::clear_has_jownwps() {
  _has_bits_[0] &= ~0x00002000u;
}
inline void BattleJoinerNotify::clear_jownwps() {
  jownwps_ = 0;
  clear_has_jownwps();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jownwps() const {
  return jownwps_;
}
inline void BattleJoinerNotify::set_jownwps(::google::protobuf::int32 value) {
  set_has_jownwps();
  jownwps_ = value;
}

// optional int32 jOwnSpecialwps = 15;
inline bool BattleJoinerNotify::has_jownspecialwps() const {
  return (_has_bits_[0] & 0x00004000u) != 0;
}
inline void BattleJoinerNotify::set_has_jownspecialwps() {
  _has_bits_[0] |= 0x00004000u;
}
inline void BattleJoinerNotify::clear_has_jownspecialwps() {
  _has_bits_[0] &= ~0x00004000u;
}
inline void BattleJoinerNotify::clear_jownspecialwps() {
  jownspecialwps_ = 0;
  clear_has_jownspecialwps();
}
inline ::google::protobuf::int32 BattleJoinerNotify::jownspecialwps() const {
  return jownspecialwps_;
}
inline void BattleJoinerNotify::set_jownspecialwps(::google::protobuf::int32 value) {
  set_has_jownspecialwps();
  jownspecialwps_ = value;
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

#endif  // PROTOBUF_MessageBattleJoinerNotify_2eproto__INCLUDED
