// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSyncBuffer.proto

#ifndef PROTOBUF_MessageSyncBuffer_2eproto__INCLUDED
#define PROTOBUF_MessageSyncBuffer_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageSyncBuffer_2eproto();
void protobuf_AssignDesc_MessageSyncBuffer_2eproto();
void protobuf_ShutdownFile_MessageSyncBuffer_2eproto();

class SyncBuffer;

// ===================================================================

class SyncBuffer : public ::google::protobuf::Message {
 public:
  SyncBuffer();
  virtual ~SyncBuffer();

  SyncBuffer(const SyncBuffer& from);

  inline SyncBuffer& operator=(const SyncBuffer& from) {
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
  static const SyncBuffer& default_instance();

  void Swap(SyncBuffer* other);

  // implements Message ----------------------------------------------

  SyncBuffer* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SyncBuffer& from);
  void MergeFrom(const SyncBuffer& from);
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

  // optional int64 pid = 1;
  inline bool has_pid() const;
  inline void clear_pid();
  static const int kPidFieldNumber = 1;
  inline ::google::protobuf::int64 pid() const;
  inline void set_pid(::google::protobuf::int64 value);

  // optional int32 opttype = 2;
  inline bool has_opttype() const;
  inline void clear_opttype();
  static const int kOpttypeFieldNumber = 2;
  inline ::google::protobuf::int32 opttype() const;
  inline void set_opttype(::google::protobuf::int32 value);

  // repeated int32 buffid = 3;
  inline int buffid_size() const;
  inline void clear_buffid();
  static const int kBuffidFieldNumber = 3;
  inline ::google::protobuf::int32 buffid(int index) const;
  inline void set_buffid(int index, ::google::protobuf::int32 value);
  inline void add_buffid(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      buffid() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_buffid();

  // repeated int32 actions = 4;
  inline int actions_size() const;
  inline void clear_actions();
  static const int kActionsFieldNumber = 4;
  inline ::google::protobuf::int32 actions(int index) const;
  inline void set_actions(int index, ::google::protobuf::int32 value);
  inline void add_actions(::google::protobuf::int32 value);
  inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
      actions() const;
  inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
      mutable_actions();

  // @@protoc_insertion_point(class_scope:Message.SyncBuffer)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();
  inline void set_has_opttype();
  inline void clear_has_opttype();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 pid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > buffid_;
  ::google::protobuf::RepeatedField< ::google::protobuf::int32 > actions_;
  ::google::protobuf::int32 opttype_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(4 + 31) / 32];

  friend void  protobuf_AddDesc_MessageSyncBuffer_2eproto();
  friend void protobuf_AssignDesc_MessageSyncBuffer_2eproto();
  friend void protobuf_ShutdownFile_MessageSyncBuffer_2eproto();

  void InitAsDefaultInstance();
  static SyncBuffer* default_instance_;
};
// ===================================================================


// ===================================================================

// SyncBuffer

// optional int64 pid = 1;
inline bool SyncBuffer::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void SyncBuffer::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void SyncBuffer::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void SyncBuffer::clear_pid() {
  pid_ = GOOGLE_LONGLONG(0);
  clear_has_pid();
}
inline ::google::protobuf::int64 SyncBuffer::pid() const {
  return pid_;
}
inline void SyncBuffer::set_pid(::google::protobuf::int64 value) {
  set_has_pid();
  pid_ = value;
}

// optional int32 opttype = 2;
inline bool SyncBuffer::has_opttype() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void SyncBuffer::set_has_opttype() {
  _has_bits_[0] |= 0x00000002u;
}
inline void SyncBuffer::clear_has_opttype() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void SyncBuffer::clear_opttype() {
  opttype_ = 0;
  clear_has_opttype();
}
inline ::google::protobuf::int32 SyncBuffer::opttype() const {
  return opttype_;
}
inline void SyncBuffer::set_opttype(::google::protobuf::int32 value) {
  set_has_opttype();
  opttype_ = value;
}

// repeated int32 buffid = 3;
inline int SyncBuffer::buffid_size() const {
  return buffid_.size();
}
inline void SyncBuffer::clear_buffid() {
  buffid_.Clear();
}
inline ::google::protobuf::int32 SyncBuffer::buffid(int index) const {
  return buffid_.Get(index);
}
inline void SyncBuffer::set_buffid(int index, ::google::protobuf::int32 value) {
  buffid_.Set(index, value);
}
inline void SyncBuffer::add_buffid(::google::protobuf::int32 value) {
  buffid_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
SyncBuffer::buffid() const {
  return buffid_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
SyncBuffer::mutable_buffid() {
  return &buffid_;
}

// repeated int32 actions = 4;
inline int SyncBuffer::actions_size() const {
  return actions_.size();
}
inline void SyncBuffer::clear_actions() {
  actions_.Clear();
}
inline ::google::protobuf::int32 SyncBuffer::actions(int index) const {
  return actions_.Get(index);
}
inline void SyncBuffer::set_actions(int index, ::google::protobuf::int32 value) {
  actions_.Set(index, value);
}
inline void SyncBuffer::add_actions(::google::protobuf::int32 value) {
  actions_.Add(value);
}
inline const ::google::protobuf::RepeatedField< ::google::protobuf::int32 >&
SyncBuffer::actions() const {
  return actions_;
}
inline ::google::protobuf::RepeatedField< ::google::protobuf::int32 >*
SyncBuffer::mutable_actions() {
  return &actions_;
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

#endif  // PROTOBUF_MessageSyncBuffer_2eproto__INCLUDED
