// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MesagePlayerCitySync.proto

#ifndef PROTOBUF_MesagePlayerCitySync_2eproto__INCLUDED
#define PROTOBUF_MesagePlayerCitySync_2eproto__INCLUDED

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
void  protobuf_AddDesc_MesagePlayerCitySync_2eproto();
void protobuf_AssignDesc_MesagePlayerCitySync_2eproto();
void protobuf_ShutdownFile_MesagePlayerCitySync_2eproto();

class PlayerCitySync;
class PlayerCitySync_CityInfo;

// ===================================================================

class PlayerCitySync_CityInfo : public ::google::protobuf::Message {
 public:
  PlayerCitySync_CityInfo();
  virtual ~PlayerCitySync_CityInfo();

  PlayerCitySync_CityInfo(const PlayerCitySync_CityInfo& from);

  inline PlayerCitySync_CityInfo& operator=(const PlayerCitySync_CityInfo& from) {
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
  static const PlayerCitySync_CityInfo& default_instance();

  void Swap(PlayerCitySync_CityInfo* other);

  // implements Message ----------------------------------------------

  PlayerCitySync_CityInfo* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayerCitySync_CityInfo& from);
  void MergeFrom(const PlayerCitySync_CityInfo& from);
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

  // optional int32 cityid = 1;
  inline bool has_cityid() const;
  inline void clear_cityid();
  static const int kCityidFieldNumber = 1;
  inline ::google::protobuf::int32 cityid() const;
  inline void set_cityid(::google::protobuf::int32 value);

  // optional int32 record = 2;
  inline bool has_record() const;
  inline void clear_record();
  static const int kRecordFieldNumber = 2;
  inline ::google::protobuf::int32 record() const;
  inline void set_record(::google::protobuf::int32 value);

  // optional int32 chgcnt1 = 3;
  inline bool has_chgcnt1() const;
  inline void clear_chgcnt1();
  static const int kChgcnt1FieldNumber = 3;
  inline ::google::protobuf::int32 chgcnt1() const;
  inline void set_chgcnt1(::google::protobuf::int32 value);

  // optional int32 chgcnt2 = 4;
  inline bool has_chgcnt2() const;
  inline void clear_chgcnt2();
  static const int kChgcnt2FieldNumber = 4;
  inline ::google::protobuf::int32 chgcnt2() const;
  inline void set_chgcnt2(::google::protobuf::int32 value);

  // optional int32 chgcnt3 = 5;
  inline bool has_chgcnt3() const;
  inline void clear_chgcnt3();
  static const int kChgcnt3FieldNumber = 5;
  inline ::google::protobuf::int32 chgcnt3() const;
  inline void set_chgcnt3(::google::protobuf::int32 value);

  // optional int32 setcnt1 = 6;
  inline bool has_setcnt1() const;
  inline void clear_setcnt1();
  static const int kSetcnt1FieldNumber = 6;
  inline ::google::protobuf::int32 setcnt1() const;
  inline void set_setcnt1(::google::protobuf::int32 value);

  // optional int32 setcnt2 = 7;
  inline bool has_setcnt2() const;
  inline void clear_setcnt2();
  static const int kSetcnt2FieldNumber = 7;
  inline ::google::protobuf::int32 setcnt2() const;
  inline void set_setcnt2(::google::protobuf::int32 value);

  // optional int32 setcnt3 = 8;
  inline bool has_setcnt3() const;
  inline void clear_setcnt3();
  static const int kSetcnt3FieldNumber = 8;
  inline ::google::protobuf::int32 setcnt3() const;
  inline void set_setcnt3(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Message.PlayerCitySync.CityInfo)
 private:
  inline void set_has_cityid();
  inline void clear_has_cityid();
  inline void set_has_record();
  inline void clear_has_record();
  inline void set_has_chgcnt1();
  inline void clear_has_chgcnt1();
  inline void set_has_chgcnt2();
  inline void clear_has_chgcnt2();
  inline void set_has_chgcnt3();
  inline void clear_has_chgcnt3();
  inline void set_has_setcnt1();
  inline void clear_has_setcnt1();
  inline void set_has_setcnt2();
  inline void clear_has_setcnt2();
  inline void set_has_setcnt3();
  inline void clear_has_setcnt3();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 cityid_;
  ::google::protobuf::int32 record_;
  ::google::protobuf::int32 chgcnt1_;
  ::google::protobuf::int32 chgcnt2_;
  ::google::protobuf::int32 chgcnt3_;
  ::google::protobuf::int32 setcnt1_;
  ::google::protobuf::int32 setcnt2_;
  ::google::protobuf::int32 setcnt3_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(8 + 31) / 32];

  friend void  protobuf_AddDesc_MesagePlayerCitySync_2eproto();
  friend void protobuf_AssignDesc_MesagePlayerCitySync_2eproto();
  friend void protobuf_ShutdownFile_MesagePlayerCitySync_2eproto();

  void InitAsDefaultInstance();
  static PlayerCitySync_CityInfo* default_instance_;
};
// -------------------------------------------------------------------

class PlayerCitySync : public ::google::protobuf::Message {
 public:
  PlayerCitySync();
  virtual ~PlayerCitySync();

  PlayerCitySync(const PlayerCitySync& from);

  inline PlayerCitySync& operator=(const PlayerCitySync& from) {
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
  static const PlayerCitySync& default_instance();

  void Swap(PlayerCitySync* other);

  // implements Message ----------------------------------------------

  PlayerCitySync* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PlayerCitySync& from);
  void MergeFrom(const PlayerCitySync& from);
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

  typedef PlayerCitySync_CityInfo CityInfo;

  // accessors -------------------------------------------------------

  // optional int64 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int64 pid() const;
  inline void set_pid(::google::protobuf::int64 value);

  // repeated .Message.PlayerCitySync.CityInfo info = 2;
  inline int info_size() const;
  inline void clear_info();
  static const int kInfoFieldNumber = 2;
  inline const ::Message::PlayerCitySync_CityInfo& info(int index) const;
  inline ::Message::PlayerCitySync_CityInfo* mutable_info(int index);
  inline ::Message::PlayerCitySync_CityInfo* add_info();
  inline const ::google::protobuf::RepeatedPtrField< ::Message::PlayerCitySync_CityInfo >&
      info() const;
  inline ::google::protobuf::RepeatedPtrField< ::Message::PlayerCitySync_CityInfo >*
      mutable_info();

  // @@protoc_insertion_point(class_scope:Message.PlayerCitySync)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 pid_;
  ::google::protobuf::RepeatedPtrField< ::Message::PlayerCitySync_CityInfo > info_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_MesagePlayerCitySync_2eproto();
  friend void protobuf_AssignDesc_MesagePlayerCitySync_2eproto();
  friend void protobuf_ShutdownFile_MesagePlayerCitySync_2eproto();

  void InitAsDefaultInstance();
  static PlayerCitySync* default_instance_;
};
// ===================================================================


// ===================================================================

// PlayerCitySync_CityInfo

// optional int32 cityid = 1;
inline bool PlayerCitySync_CityInfo::has_cityid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_cityid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayerCitySync_CityInfo::clear_has_cityid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayerCitySync_CityInfo::clear_cityid() {
  cityid_ = 0;
  clear_has_cityid();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::cityid() const {
  return cityid_;
}
inline void PlayerCitySync_CityInfo::set_cityid(::google::protobuf::int32 value) {
  set_has_cityid();
  cityid_ = value;
}

// optional int32 record = 2;
inline bool PlayerCitySync_CityInfo::has_record() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_record() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PlayerCitySync_CityInfo::clear_has_record() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PlayerCitySync_CityInfo::clear_record() {
  record_ = 0;
  clear_has_record();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::record() const {
  return record_;
}
inline void PlayerCitySync_CityInfo::set_record(::google::protobuf::int32 value) {
  set_has_record();
  record_ = value;
}

// optional int32 chgcnt1 = 3;
inline bool PlayerCitySync_CityInfo::has_chgcnt1() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_chgcnt1() {
  _has_bits_[0] |= 0x00000004u;
}
inline void PlayerCitySync_CityInfo::clear_has_chgcnt1() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void PlayerCitySync_CityInfo::clear_chgcnt1() {
  chgcnt1_ = 0;
  clear_has_chgcnt1();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::chgcnt1() const {
  return chgcnt1_;
}
inline void PlayerCitySync_CityInfo::set_chgcnt1(::google::protobuf::int32 value) {
  set_has_chgcnt1();
  chgcnt1_ = value;
}

// optional int32 chgcnt2 = 4;
inline bool PlayerCitySync_CityInfo::has_chgcnt2() const {
  return (_has_bits_[0] & 0x00000008u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_chgcnt2() {
  _has_bits_[0] |= 0x00000008u;
}
inline void PlayerCitySync_CityInfo::clear_has_chgcnt2() {
  _has_bits_[0] &= ~0x00000008u;
}
inline void PlayerCitySync_CityInfo::clear_chgcnt2() {
  chgcnt2_ = 0;
  clear_has_chgcnt2();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::chgcnt2() const {
  return chgcnt2_;
}
inline void PlayerCitySync_CityInfo::set_chgcnt2(::google::protobuf::int32 value) {
  set_has_chgcnt2();
  chgcnt2_ = value;
}

// optional int32 chgcnt3 = 5;
inline bool PlayerCitySync_CityInfo::has_chgcnt3() const {
  return (_has_bits_[0] & 0x00000010u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_chgcnt3() {
  _has_bits_[0] |= 0x00000010u;
}
inline void PlayerCitySync_CityInfo::clear_has_chgcnt3() {
  _has_bits_[0] &= ~0x00000010u;
}
inline void PlayerCitySync_CityInfo::clear_chgcnt3() {
  chgcnt3_ = 0;
  clear_has_chgcnt3();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::chgcnt3() const {
  return chgcnt3_;
}
inline void PlayerCitySync_CityInfo::set_chgcnt3(::google::protobuf::int32 value) {
  set_has_chgcnt3();
  chgcnt3_ = value;
}

// optional int32 setcnt1 = 6;
inline bool PlayerCitySync_CityInfo::has_setcnt1() const {
  return (_has_bits_[0] & 0x00000020u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_setcnt1() {
  _has_bits_[0] |= 0x00000020u;
}
inline void PlayerCitySync_CityInfo::clear_has_setcnt1() {
  _has_bits_[0] &= ~0x00000020u;
}
inline void PlayerCitySync_CityInfo::clear_setcnt1() {
  setcnt1_ = 0;
  clear_has_setcnt1();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::setcnt1() const {
  return setcnt1_;
}
inline void PlayerCitySync_CityInfo::set_setcnt1(::google::protobuf::int32 value) {
  set_has_setcnt1();
  setcnt1_ = value;
}

// optional int32 setcnt2 = 7;
inline bool PlayerCitySync_CityInfo::has_setcnt2() const {
  return (_has_bits_[0] & 0x00000040u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_setcnt2() {
  _has_bits_[0] |= 0x00000040u;
}
inline void PlayerCitySync_CityInfo::clear_has_setcnt2() {
  _has_bits_[0] &= ~0x00000040u;
}
inline void PlayerCitySync_CityInfo::clear_setcnt2() {
  setcnt2_ = 0;
  clear_has_setcnt2();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::setcnt2() const {
  return setcnt2_;
}
inline void PlayerCitySync_CityInfo::set_setcnt2(::google::protobuf::int32 value) {
  set_has_setcnt2();
  setcnt2_ = value;
}

// optional int32 setcnt3 = 8;
inline bool PlayerCitySync_CityInfo::has_setcnt3() const {
  return (_has_bits_[0] & 0x00000080u) != 0;
}
inline void PlayerCitySync_CityInfo::set_has_setcnt3() {
  _has_bits_[0] |= 0x00000080u;
}
inline void PlayerCitySync_CityInfo::clear_has_setcnt3() {
  _has_bits_[0] &= ~0x00000080u;
}
inline void PlayerCitySync_CityInfo::clear_setcnt3() {
  setcnt3_ = 0;
  clear_has_setcnt3();
}
inline ::google::protobuf::int32 PlayerCitySync_CityInfo::setcnt3() const {
  return setcnt3_;
}
inline void PlayerCitySync_CityInfo::set_setcnt3(::google::protobuf::int32 value) {
  set_has_setcnt3();
  setcnt3_ = value;
}

// -------------------------------------------------------------------

// PlayerCitySync

// optional int64 pid = 1;
inline bool PlayerCitySync::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PlayerCitySync::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PlayerCitySync::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PlayerCitySync::clear_pid() {
  pid_ = GOOGLE_LONGLONG(0);
  clear_has_pid();
}
inline ::google::protobuf::int64 PlayerCitySync::pid() const {
  return pid_;
}
inline void PlayerCitySync::set_pid(::google::protobuf::int64 value) {
  set_has_pid();
  pid_ = value;
}

// repeated .Message.PlayerCitySync.CityInfo info = 2;
inline int PlayerCitySync::info_size() const {
  return info_.size();
}
inline void PlayerCitySync::clear_info() {
  info_.Clear();
}
inline const ::Message::PlayerCitySync_CityInfo& PlayerCitySync::info(int index) const {
  return info_.Get(index);
}
inline ::Message::PlayerCitySync_CityInfo* PlayerCitySync::mutable_info(int index) {
  return info_.Mutable(index);
}
inline ::Message::PlayerCitySync_CityInfo* PlayerCitySync::add_info() {
  return info_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Message::PlayerCitySync_CityInfo >&
PlayerCitySync::info() const {
  return info_;
}
inline ::google::protobuf::RepeatedPtrField< ::Message::PlayerCitySync_CityInfo >*
PlayerCitySync::mutable_info() {
  return &info_;
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

#endif  // PROTOBUF_MesagePlayerCitySync_2eproto__INCLUDED
