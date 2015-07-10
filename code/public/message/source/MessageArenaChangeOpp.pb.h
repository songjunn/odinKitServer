// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageArenaChangeOpp.proto

#ifndef PROTOBUF_MessageArenaChangeOpp_2eproto__INCLUDED
#define PROTOBUF_MessageArenaChangeOpp_2eproto__INCLUDED

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
#include "MessageArenaPlayerData.pb.h"
// @@protoc_insertion_point(includes)

namespace Message {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_MessageArenaChangeOpp_2eproto();
void protobuf_AssignDesc_MessageArenaChangeOpp_2eproto();
void protobuf_ShutdownFile_MessageArenaChangeOpp_2eproto();

class ArenaChangeOppRequest;
class ArenaChangeOppResponse;

// ===================================================================

class ArenaChangeOppRequest : public ::google::protobuf::Message {
 public:
  ArenaChangeOppRequest();
  virtual ~ArenaChangeOppRequest();

  ArenaChangeOppRequest(const ArenaChangeOppRequest& from);

  inline ArenaChangeOppRequest& operator=(const ArenaChangeOppRequest& from) {
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
  static const ArenaChangeOppRequest& default_instance();

  void Swap(ArenaChangeOppRequest* other);

  // implements Message ----------------------------------------------

  ArenaChangeOppRequest* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArenaChangeOppRequest& from);
  void MergeFrom(const ArenaChangeOppRequest& from);
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

  // @@protoc_insertion_point(class_scope:Message.ArenaChangeOppRequest)
 private:
  inline void set_has_pid();
  inline void clear_has_pid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 pid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_MessageArenaChangeOpp_2eproto();
  friend void protobuf_AssignDesc_MessageArenaChangeOpp_2eproto();
  friend void protobuf_ShutdownFile_MessageArenaChangeOpp_2eproto();

  void InitAsDefaultInstance();
  static ArenaChangeOppRequest* default_instance_;
};
// -------------------------------------------------------------------

class ArenaChangeOppResponse : public ::google::protobuf::Message {
 public:
  ArenaChangeOppResponse();
  virtual ~ArenaChangeOppResponse();

  ArenaChangeOppResponse(const ArenaChangeOppResponse& from);

  inline ArenaChangeOppResponse& operator=(const ArenaChangeOppResponse& from) {
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
  static const ArenaChangeOppResponse& default_instance();

  void Swap(ArenaChangeOppResponse* other);

  // implements Message ----------------------------------------------

  ArenaChangeOppResponse* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const ArenaChangeOppResponse& from);
  void MergeFrom(const ArenaChangeOppResponse& from);
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

  // optional int64 old_pid = 1;
  inline bool has_old_pid() const;
  inline void clear_old_pid();
  static const int kOldPidFieldNumber = 1;
  inline ::google::protobuf::int64 old_pid() const;
  inline void set_old_pid(::google::protobuf::int64 value);

  // optional .Message.ArenaPlayer new_player = 2;
  inline bool has_new_player() const;
  inline void clear_new_player();
  static const int kNewPlayerFieldNumber = 2;
  inline const ::Message::ArenaPlayer& new_player() const;
  inline ::Message::ArenaPlayer* mutable_new_player();
  inline ::Message::ArenaPlayer* release_new_player();
  inline void set_allocated_new_player(::Message::ArenaPlayer* new_player);

  // optional int32 result = 3;
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 3;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:Message.ArenaChangeOppResponse)
 private:
  inline void set_has_old_pid();
  inline void clear_has_old_pid();
  inline void set_has_new_player();
  inline void clear_has_new_player();
  inline void set_has_result();
  inline void clear_has_result();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 old_pid_;
  ::Message::ArenaPlayer* new_player_;
  ::google::protobuf::int32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(3 + 31) / 32];

  friend void  protobuf_AddDesc_MessageArenaChangeOpp_2eproto();
  friend void protobuf_AssignDesc_MessageArenaChangeOpp_2eproto();
  friend void protobuf_ShutdownFile_MessageArenaChangeOpp_2eproto();

  void InitAsDefaultInstance();
  static ArenaChangeOppResponse* default_instance_;
};
// ===================================================================


// ===================================================================

// ArenaChangeOppRequest

// optional int64 pid = 1;
inline bool ArenaChangeOppRequest::has_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ArenaChangeOppRequest::set_has_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ArenaChangeOppRequest::clear_has_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ArenaChangeOppRequest::clear_pid() {
  pid_ = GOOGLE_LONGLONG(0);
  clear_has_pid();
}
inline ::google::protobuf::int64 ArenaChangeOppRequest::pid() const {
  return pid_;
}
inline void ArenaChangeOppRequest::set_pid(::google::protobuf::int64 value) {
  set_has_pid();
  pid_ = value;
}

// -------------------------------------------------------------------

// ArenaChangeOppResponse

// optional int64 old_pid = 1;
inline bool ArenaChangeOppResponse::has_old_pid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void ArenaChangeOppResponse::set_has_old_pid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void ArenaChangeOppResponse::clear_has_old_pid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void ArenaChangeOppResponse::clear_old_pid() {
  old_pid_ = GOOGLE_LONGLONG(0);
  clear_has_old_pid();
}
inline ::google::protobuf::int64 ArenaChangeOppResponse::old_pid() const {
  return old_pid_;
}
inline void ArenaChangeOppResponse::set_old_pid(::google::protobuf::int64 value) {
  set_has_old_pid();
  old_pid_ = value;
}

// optional .Message.ArenaPlayer new_player = 2;
inline bool ArenaChangeOppResponse::has_new_player() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void ArenaChangeOppResponse::set_has_new_player() {
  _has_bits_[0] |= 0x00000002u;
}
inline void ArenaChangeOppResponse::clear_has_new_player() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void ArenaChangeOppResponse::clear_new_player() {
  if (new_player_ != NULL) new_player_->::Message::ArenaPlayer::Clear();
  clear_has_new_player();
}
inline const ::Message::ArenaPlayer& ArenaChangeOppResponse::new_player() const {
  return new_player_ != NULL ? *new_player_ : *default_instance_->new_player_;
}
inline ::Message::ArenaPlayer* ArenaChangeOppResponse::mutable_new_player() {
  set_has_new_player();
  if (new_player_ == NULL) new_player_ = new ::Message::ArenaPlayer;
  return new_player_;
}
inline ::Message::ArenaPlayer* ArenaChangeOppResponse::release_new_player() {
  clear_has_new_player();
  ::Message::ArenaPlayer* temp = new_player_;
  new_player_ = NULL;
  return temp;
}
inline void ArenaChangeOppResponse::set_allocated_new_player(::Message::ArenaPlayer* new_player) {
  delete new_player_;
  new_player_ = new_player;
  if (new_player) {
    set_has_new_player();
  } else {
    clear_has_new_player();
  }
}

// optional int32 result = 3;
inline bool ArenaChangeOppResponse::has_result() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void ArenaChangeOppResponse::set_has_result() {
  _has_bits_[0] |= 0x00000004u;
}
inline void ArenaChangeOppResponse::clear_has_result() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void ArenaChangeOppResponse::clear_result() {
  result_ = 0;
  clear_has_result();
}
inline ::google::protobuf::int32 ArenaChangeOppResponse::result() const {
  return result_;
}
inline void ArenaChangeOppResponse::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
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

#endif  // PROTOBUF_MessageArenaChangeOpp_2eproto__INCLUDED
