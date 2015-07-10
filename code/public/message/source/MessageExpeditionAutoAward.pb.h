// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageExpeditionAutoAward.proto

#ifndef PROTOBUF_MessageExpeditionAutoAward_2eproto__INCLUDED
#define PROTOBUF_MessageExpeditionAutoAward_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
void protobuf_AssignDesc_MessageExpeditionAutoAward_2eproto();
void protobuf_ShutdownFile_MessageExpeditionAutoAward_2eproto();

class ExpeditionAutoAward;
class ExpeditionAutoAward_AutoAward;

// ===================================================================

class ExpeditionAutoAward_AutoAward : public ::google::protobuf::Message {
 public:
  ExpeditionAutoAward_AutoAward();
  virtual ~ExpeditionAutoAward_AutoAward();

  ExpeditionAutoAward_AutoAward(const ExpeditionAutoAward_AutoAward& from);

  inline ExpeditionAutoAward_AutoAward& operator=(const ExpeditionAutoAward_AutoAward& from) {
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
  static const ExpeditionAutoAward_AutoAward& default_instance();

  void Swap(ExpeditionAutoAward_AutoAward* other);

  // implements Message ----------------------------------------------

  ExpeditionAutoAward_AutoAward* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ExpeditionAutoAward_AutoAward& from);
  void MergeFrom(const ExpeditionAutoAward_AutoAward& from);
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

  // optional int32 gainexp = 1;
  inline bool has_gainexp() const;
  inline void clear_gainexp();
  static const int kGainexpFieldNumber = 1;
  inline ::google::protobuf::int32 gainexp() const;
  inline void set_gainexp(::google::protobuf::int32 value);

  // optional int32 gainsilver = 3;
  inline bool has_gainsilver() const;
  inline void clear_gainsilver();
  static const int kGainsilverFieldNumber = 3;
  inline ::google::protobuf::int32 gainsilver() const;
  inline void set_gainsilver(::google::protobuf::int32 value);

  // repeated int32 itemid = 4;
  inline int itemid_size() const;
  inline void clear_itemid();
  static const int kItemidFieldNumber = 4;
  inline ::google::protobuf::int32 itemid(int index) const;
  inline void set_itemid(int index, ::google::protobuf::int32 value);
  inline void add_itemid(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      itemid() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_itemid();

  // repeated int32 itemstack = 5;
  inline int itemstack_size() const;
  inline void clear_itemstack();
  static const int kItemstackFieldNumber = 5;
  inline ::google::protobuf::int32 itemstack(int index) const;
  inline void set_itemstack(int index, ::google::protobuf::int32 value);
  inline void add_itemstack(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      itemstack() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_itemstack();

  // @@protoc_insertion_point(class_scope:Message.ExpeditionAutoAward.AutoAward)
 private:
  inline void set_has_gainexp();
  inline void clear_has_gainexp();
  inline void set_has_gainsilver();
  inline void clear_has_gainsilver();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 gainexp_;
  ::google::protobuf::int32 gainsilver_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > itemid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > itemstack_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  friend void protobuf_AssignDesc_MessageExpeditionAutoAward_2eproto();
  friend void protobuf_ShutdownFile_MessageExpeditionAutoAward_2eproto();

  void InitAsDefaultInstance();
  static ExpeditionAutoAward_AutoAward* default_instance_;
};
// -------------------------------------------------------------------

class ExpeditionAutoAward : public ::google::protobuf::Message {
 public:
  ExpeditionAutoAward();
  virtual ~ExpeditionAutoAward();

  ExpeditionAutoAward(const ExpeditionAutoAward& from);

  inline ExpeditionAutoAward& operator=(const ExpeditionAutoAward& from) {
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
  static const ExpeditionAutoAward& default_instance();

  void Swap(ExpeditionAutoAward* other);

  // implements Message ----------------------------------------------

  ExpeditionAutoAward* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ExpeditionAutoAward& from);
  void MergeFrom(const ExpeditionAutoAward& from);
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

  typedef ExpeditionAutoAward_AutoAward AutoAward;

  // accessors -------------------------------------------------------

  // repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
  inline int autoawards_size() const;
  inline void clear_autoawards();
  static const int kAutoawardsFieldNumber = 1;
  inline const ::Message::ExpeditionAutoAward_AutoAward& autoawards(int index) const;
  inline ::Message::ExpeditionAutoAward_AutoAward* mutable_autoawards(int index);
  inline ::Message::ExpeditionAutoAward_AutoAward* add_autoawards();
  inline const ::google::protobuf::RepeatedPtrField< ::Message::ExpeditionAutoAward_AutoAward >&
      autoawards() const;
  inline ::google::protobuf::RepeatedPtrField< ::Message::ExpeditionAutoAward_AutoAward >*
      mutable_autoawards();

  // @@protoc_insertion_point(class_scope:Message.ExpeditionAutoAward)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::RepeatedPtrField< ::Message::ExpeditionAutoAward_AutoAward > autoawards_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MessageExpeditionAutoAward_2eproto();
  friend void protobuf_AssignDesc_MessageExpeditionAutoAward_2eproto();
  friend void protobuf_ShutdownFile_MessageExpeditionAutoAward_2eproto();

  void InitAsDefaultInstance();
  static ExpeditionAutoAward* default_instance_;
};
// ===================================================================


// ===================================================================

// ExpeditionAutoAward_AutoAward

// optional int32 gainexp = 1;
inline bool ExpeditionAutoAward_AutoAward::has_gainexp() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ExpeditionAutoAward_AutoAward::set_has_gainexp() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ExpeditionAutoAward_AutoAward::clear_has_gainexp() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ExpeditionAutoAward_AutoAward::clear_gainexp() {
  gainexp_ = 0;
  clear_has_gainexp();
}
inline ::google::protobuf::int32 ExpeditionAutoAward_AutoAward::gainexp() const {
  return gainexp_;
}
inline void ExpeditionAutoAward_AutoAward::set_gainexp(::google::protobuf::int32 value) {
  set_has_gainexp();
  gainexp_ = value;
}

// optional int32 gainsilver = 3;
inline bool ExpeditionAutoAward_AutoAward::has_gainsilver() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ExpeditionAutoAward_AutoAward::set_has_gainsilver() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ExpeditionAutoAward_AutoAward::clear_has_gainsilver() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ExpeditionAutoAward_AutoAward::clear_gainsilver() {
  gainsilver_ = 0;
  clear_has_gainsilver();
}
inline ::google::protobuf::int32 ExpeditionAutoAward_AutoAward::gainsilver() const {
  return gainsilver_;
}
inline void ExpeditionAutoAward_AutoAward::set_gainsilver(::google::protobuf::int32 value) {
  set_has_gainsilver();
  gainsilver_ = value;
}

// repeated int32 itemid = 4;
inline int ExpeditionAutoAward_AutoAward::itemid_size() const {
  return itemid_.size();
}
inline void ExpeditionAutoAward_AutoAward::clear_itemid() {
  itemid_.Clear();
}
inline ::google::protobuf::int32 ExpeditionAutoAward_AutoAward::itemid(int index) const {
  return itemid_.Get(index);
}
inline void ExpeditionAutoAward_AutoAward::set_itemid(int index, ::google::protobuf::int32 value) {
  itemid_.Set(index, value);
}
inline void ExpeditionAutoAward_AutoAward::add_itemid(::google::protobuf::int32 value) {
  itemid_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ExpeditionAutoAward_AutoAward::itemid() const {
  return itemid_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ExpeditionAutoAward_AutoAward::mutable_itemid() {
  return &itemid_;
}

// repeated int32 itemstack = 5;
inline int ExpeditionAutoAward_AutoAward::itemstack_size() const {
  return itemstack_.size();
}
inline void ExpeditionAutoAward_AutoAward::clear_itemstack() {
  itemstack_.Clear();
}
inline ::google::protobuf::int32 ExpeditionAutoAward_AutoAward::itemstack(int index) const {
  return itemstack_.Get(index);
}
inline void ExpeditionAutoAward_AutoAward::set_itemstack(int index, ::google::protobuf::int32 value) {
  itemstack_.Set(index, value);
}
inline void ExpeditionAutoAward_AutoAward::add_itemstack(::google::protobuf::int32 value) {
  itemstack_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
ExpeditionAutoAward_AutoAward::itemstack() const {
  return itemstack_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
ExpeditionAutoAward_AutoAward::mutable_itemstack() {
  return &itemstack_;
}

// -------------------------------------------------------------------

// ExpeditionAutoAward

// repeated .Message.ExpeditionAutoAward.AutoAward autoawards = 1;
inline int ExpeditionAutoAward::autoawards_size() const {
  return autoawards_.size();
}
inline void ExpeditionAutoAward::clear_autoawards() {
  autoawards_.Clear();
}
inline const ::Message::ExpeditionAutoAward_AutoAward& ExpeditionAutoAward::autoawards(int index) const {
  return autoawards_.Get(index);
}
inline ::Message::ExpeditionAutoAward_AutoAward* ExpeditionAutoAward::mutable_autoawards(int index) {
  return autoawards_.Mutable(index);
}
inline ::Message::ExpeditionAutoAward_AutoAward* ExpeditionAutoAward::add_autoawards() {
  return autoawards_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::Message::ExpeditionAutoAward_AutoAward >&
ExpeditionAutoAward::autoawards() const {
  return autoawards_;
}
inline ::google::protobuf::RepeatedPtrField< ::Message::ExpeditionAutoAward_AutoAward >*
ExpeditionAutoAward::mutable_autoawards() {
  return &autoawards_;
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

#endif  // PROTOBUF_MessageExpeditionAutoAward_2eproto__INCLUDED
