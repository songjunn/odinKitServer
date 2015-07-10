// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageBossRewardKill.proto

#ifndef PROTOBUF_MessageBossRewardKill_2eproto__INCLUDED
#define PROTOBUF_MessageBossRewardKill_2eproto__INCLUDED

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
void  protobuf_AddDesc_MessageBossRewardKill_2eproto();
void protobuf_AssignDesc_MessageBossRewardKill_2eproto();
void protobuf_ShutdownFile_MessageBossRewardKill_2eproto();

class BossRewardKill;

// ===================================================================

class BossRewardKill : public ::google::protobuf::Message {
 public:
  BossRewardKill();
  virtual ~BossRewardKill();

  BossRewardKill(const BossRewardKill& from);

  inline BossRewardKill& operator=(const BossRewardKill& from) {
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
  static const BossRewardKill& default_instance();

  void Swap(BossRewardKill* other);

  // implements Message ----------------------------------------------

  BossRewardKill* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BossRewardKill& from);
  void MergeFrom(const BossRewardKill& from);
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

  // optional int32 silver = 1;
  inline bool has_silver() const;
  inline void clear_silver();
  static const int kSilverFieldNumber = 1;
  inline ::google::protobuf::int32 silver() const;
  inline void set_silver(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Message.BossRewardKill)
 private:
  inline void set_has_silver();
  inline void clear_has_silver();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 silver_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MessageBossRewardKill_2eproto();
  friend void protobuf_AssignDesc_MessageBossRewardKill_2eproto();
  friend void protobuf_ShutdownFile_MessageBossRewardKill_2eproto();

  void InitAsDefaultInstance();
  static BossRewardKill* default_instance_;
};
// ===================================================================


// ===================================================================

// BossRewardKill

// optional int32 silver = 1;
inline bool BossRewardKill::has_silver() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void BossRewardKill::set_has_silver() {
  _has_bits_[0] |= 0x00000001u;
}
inline void BossRewardKill::clear_has_silver() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void BossRewardKill::clear_silver() {
  silver_ = 0;
  clear_has_silver();
}
inline ::google::protobuf::int32 BossRewardKill::silver() const {
  return silver_;
}
inline void BossRewardKill::set_silver(::google::protobuf::int32 value) {
  set_has_silver();
  silver_ = value;
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

#endif  // PROTOBUF_MessageBossRewardKill_2eproto__INCLUDED
