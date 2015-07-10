// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageArenaPlayerDataRequest.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageArenaPlayerDataRequest.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace Message {

namespace {

const ::google::protobuf::Descriptor* ArenaPlayerResponse_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArenaPlayerResponse_reflection_ = NULL;
const ::google::protobuf::Descriptor* ArenaPlayerRequest_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ArenaPlayerRequest_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageArenaPlayerDataRequest_2eproto() {
  protobuf_AddDesc_MessageArenaPlayerDataRequest_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageArenaPlayerDataRequest.proto");
  GOOGLE_CHECK(file != NULL);
  ArenaPlayerResponse_descriptor_ = file->message_type(0);
  static const int ArenaPlayerResponse_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerResponse, player_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerResponse, result_),
  };
  ArenaPlayerResponse_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArenaPlayerResponse_descriptor_,
      ArenaPlayerResponse::default_instance_,
      ArenaPlayerResponse_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerResponse, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerResponse, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArenaPlayerResponse));
  ArenaPlayerRequest_descriptor_ = file->message_type(1);
  static const int ArenaPlayerRequest_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerRequest, request_),
  };
  ArenaPlayerRequest_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      ArenaPlayerRequest_descriptor_,
      ArenaPlayerRequest::default_instance_,
      ArenaPlayerRequest_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerRequest, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ArenaPlayerRequest, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(ArenaPlayerRequest));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageArenaPlayerDataRequest_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArenaPlayerResponse_descriptor_, &ArenaPlayerResponse::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    ArenaPlayerRequest_descriptor_, &ArenaPlayerRequest::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageArenaPlayerDataRequest_2eproto() {
  delete ArenaPlayerResponse::default_instance_;
  delete ArenaPlayerResponse_reflection_;
  delete ArenaPlayerRequest::default_instance_;
  delete ArenaPlayerRequest_reflection_;
}

void protobuf_AddDesc_MessageArenaPlayerDataRequest_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::Message::protobuf_AddDesc_MessageArenaPlayerData_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n#MessageArenaPlayerDataRequest.proto\022\007M"
    "essage\032\034MessageArenaPlayerData.proto\"K\n\023"
    "ArenaPlayerResponse\022$\n\006player\030\001 \003(\0132\024.Me"
    "ssage.ArenaPlayer\022\016\n\006result\030\002 \001(\005\"%\n\022Are"
    "naPlayerRequest\022\017\n\007request\030\001 \001(\005", 192);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageArenaPlayerDataRequest.proto", &protobuf_RegisterTypes);
  ArenaPlayerResponse::default_instance_ = new ArenaPlayerResponse();
  ArenaPlayerRequest::default_instance_ = new ArenaPlayerRequest();
  ArenaPlayerResponse::default_instance_->InitAsDefaultInstance();
  ArenaPlayerRequest::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageArenaPlayerDataRequest_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageArenaPlayerDataRequest_2eproto {
  StaticDescriptorInitializer_MessageArenaPlayerDataRequest_2eproto() {
    protobuf_AddDesc_MessageArenaPlayerDataRequest_2eproto();
  }
} static_descriptor_initializer_MessageArenaPlayerDataRequest_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int ArenaPlayerResponse::kPlayerFieldNumber;
const int ArenaPlayerResponse::kResultFieldNumber;
#endif  // !_MSC_VER

ArenaPlayerResponse::ArenaPlayerResponse()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArenaPlayerResponse::InitAsDefaultInstance() {
}

ArenaPlayerResponse::ArenaPlayerResponse(const ArenaPlayerResponse& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArenaPlayerResponse::SharedCtor() {
  _cached_size_ = 0;
  result_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArenaPlayerResponse::~ArenaPlayerResponse() {
  SharedDtor();
}

void ArenaPlayerResponse::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArenaPlayerResponse::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArenaPlayerResponse::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArenaPlayerResponse_descriptor_;
}

const ArenaPlayerResponse& ArenaPlayerResponse::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageArenaPlayerDataRequest_2eproto();
  return *default_instance_;
}

ArenaPlayerResponse* ArenaPlayerResponse::default_instance_ = NULL;

ArenaPlayerResponse* ArenaPlayerResponse::New() const {
  return new ArenaPlayerResponse;
}

void ArenaPlayerResponse::Clear() {
  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    result_ = 0;
  }
  player_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArenaPlayerResponse::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .Message.ArenaPlayer player = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_LENGTH_DELIMITED) {
         parse_player:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_player()));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(10)) goto parse_player;
        if (input->ExpectTag(16)) goto parse_result;
        break;
      }

      // optional int32 result = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_result:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &result_)));
          set_has_result();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ArenaPlayerResponse::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // repeated .Message.ArenaPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->player(i), output);
  }

  // optional int32 result = 2;
  if (has_result()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->result(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArenaPlayerResponse::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // repeated .Message.ArenaPlayer player = 1;
  for (int i = 0; i < this->player_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->player(i), target);
  }

  // optional int32 result = 2;
  if (has_result()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->result(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArenaPlayerResponse::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    // optional int32 result = 2;
    if (has_result()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->result());
    }

  }
  // repeated .Message.ArenaPlayer player = 1;
  total_size += 1 * this->player_size();
  for (int i = 0; i < this->player_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->player(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArenaPlayerResponse::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArenaPlayerResponse* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArenaPlayerResponse*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArenaPlayerResponse::MergeFrom(const ArenaPlayerResponse& from) {
  GOOGLE_CHECK_NE(&from, this);
  player_.MergeFrom(from.player_);
  if (from._has_bits_[1 / 32] & (0xffu << (1 % 32))) {
    if (from.has_result()) {
      set_result(from.result());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArenaPlayerResponse::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArenaPlayerResponse::CopyFrom(const ArenaPlayerResponse& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArenaPlayerResponse::IsInitialized() const {

  return true;
}

void ArenaPlayerResponse::Swap(ArenaPlayerResponse* other) {
  if (other != this) {
    player_.Swap(&other->player_);
    std::swap(result_, other->result_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArenaPlayerResponse::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArenaPlayerResponse_descriptor_;
  metadata.reflection = ArenaPlayerResponse_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int ArenaPlayerRequest::kRequestFieldNumber;
#endif  // !_MSC_VER

ArenaPlayerRequest::ArenaPlayerRequest()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void ArenaPlayerRequest::InitAsDefaultInstance() {
}

ArenaPlayerRequest::ArenaPlayerRequest(const ArenaPlayerRequest& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void ArenaPlayerRequest::SharedCtor() {
  _cached_size_ = 0;
  request_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

ArenaPlayerRequest::~ArenaPlayerRequest() {
  SharedDtor();
}

void ArenaPlayerRequest::SharedDtor() {
  if (this != default_instance_) {
  }
}

void ArenaPlayerRequest::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ArenaPlayerRequest::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ArenaPlayerRequest_descriptor_;
}

const ArenaPlayerRequest& ArenaPlayerRequest::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageArenaPlayerDataRequest_2eproto();
  return *default_instance_;
}

ArenaPlayerRequest* ArenaPlayerRequest::default_instance_ = NULL;

ArenaPlayerRequest* ArenaPlayerRequest::New() const {
  return new ArenaPlayerRequest;
}

void ArenaPlayerRequest::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    request_ = 0;
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool ArenaPlayerRequest::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 request = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &request_)));
          set_has_request();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectAtEnd()) return true;
        break;
      }

      default: {
      handle_uninterpreted:
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          return true;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
  return true;
#undef DO_
}

void ArenaPlayerRequest::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional int32 request = 1;
  if (has_request()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->request(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* ArenaPlayerRequest::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional int32 request = 1;
  if (has_request()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->request(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int ArenaPlayerRequest::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 request = 1;
    if (has_request()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->request());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ArenaPlayerRequest::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const ArenaPlayerRequest* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const ArenaPlayerRequest*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void ArenaPlayerRequest::MergeFrom(const ArenaPlayerRequest& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_request()) {
      set_request(from.request());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void ArenaPlayerRequest::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ArenaPlayerRequest::CopyFrom(const ArenaPlayerRequest& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool ArenaPlayerRequest::IsInitialized() const {

  return true;
}

void ArenaPlayerRequest::Swap(ArenaPlayerRequest* other) {
  if (other != this) {
    std::swap(request_, other->request_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata ArenaPlayerRequest::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ArenaPlayerRequest_descriptor_;
  metadata.reflection = ArenaPlayerRequest_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
