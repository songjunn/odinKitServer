// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: MessageSignCompRespond.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "MessageSignCompRespond.pb.h"

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

const ::google::protobuf::Descriptor* SignCompRespond_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SignCompRespond_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_MessageSignCompRespond_2eproto() {
  protobuf_AddDesc_MessageSignCompRespond_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "MessageSignCompRespond.proto");
  GOOGLE_CHECK(file != NULL);
  SignCompRespond_descriptor_ = file->message_type(0);
  static const int SignCompRespond_offsets_[12] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, btoday_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, curtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, badagenum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, getdays_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, continuedays_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, totaldays_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, gainnum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, extranum_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, bsign_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, signcost_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, freetimes_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, morrownum_),
  };
  SignCompRespond_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      SignCompRespond_descriptor_,
      SignCompRespond::default_instance_,
      SignCompRespond_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SignCompRespond, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(SignCompRespond));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_MessageSignCompRespond_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    SignCompRespond_descriptor_, &SignCompRespond::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_MessageSignCompRespond_2eproto() {
  delete SignCompRespond::default_instance_;
  delete SignCompRespond_reflection_;
}

void protobuf_AddDesc_MessageSignCompRespond_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\034MessageSignCompRespond.proto\022\007Message\""
    "\351\001\n\017SignCompRespond\022\016\n\006btoday\030\001 \001(\010\022\017\n\007c"
    "urtime\030\002 \001(\004\022\021\n\tbadagenum\030\003 \001(\005\022\017\n\007getda"
    "ys\030\004 \001(\005\022\024\n\014continuedays\030\005 \001(\005\022\021\n\ttotald"
    "ays\030\006 \001(\005\022\017\n\007gainnum\030\007 \001(\005\022\020\n\010extranum\030\010"
    " \001(\005\022\r\n\005bsign\030\t \003(\010\022\020\n\010signcost\030\n \001(\005\022\021\n"
    "\tfreetimes\030\013 \001(\005\022\021\n\tmorrownum\030\014 \001(\005", 275);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "MessageSignCompRespond.proto", &protobuf_RegisterTypes);
  SignCompRespond::default_instance_ = new SignCompRespond();
  SignCompRespond::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_MessageSignCompRespond_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_MessageSignCompRespond_2eproto {
  StaticDescriptorInitializer_MessageSignCompRespond_2eproto() {
    protobuf_AddDesc_MessageSignCompRespond_2eproto();
  }
} static_descriptor_initializer_MessageSignCompRespond_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int SignCompRespond::kBtodayFieldNumber;
const int SignCompRespond::kCurtimeFieldNumber;
const int SignCompRespond::kBadagenumFieldNumber;
const int SignCompRespond::kGetdaysFieldNumber;
const int SignCompRespond::kContinuedaysFieldNumber;
const int SignCompRespond::kTotaldaysFieldNumber;
const int SignCompRespond::kGainnumFieldNumber;
const int SignCompRespond::kExtranumFieldNumber;
const int SignCompRespond::kBsignFieldNumber;
const int SignCompRespond::kSigncostFieldNumber;
const int SignCompRespond::kFreetimesFieldNumber;
const int SignCompRespond::kMorrownumFieldNumber;
#endif  // !_MSC_VER

SignCompRespond::SignCompRespond()
  : ::google::protobuf::Message() {
  SharedCtor();
}

void SignCompRespond::InitAsDefaultInstance() {
}

SignCompRespond::SignCompRespond(const SignCompRespond& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
}

void SignCompRespond::SharedCtor() {
  _cached_size_ = 0;
  btoday_ = false;
  curtime_ = GOOGLE_ULONGLONG(0);
  badagenum_ = 0;
  getdays_ = 0;
  continuedays_ = 0;
  totaldays_ = 0;
  gainnum_ = 0;
  extranum_ = 0;
  signcost_ = 0;
  freetimes_ = 0;
  morrownum_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

SignCompRespond::~SignCompRespond() {
  SharedDtor();
}

void SignCompRespond::SharedDtor() {
  if (this != default_instance_) {
  }
}

void SignCompRespond::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SignCompRespond::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SignCompRespond_descriptor_;
}

const SignCompRespond& SignCompRespond::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_MessageSignCompRespond_2eproto();
  return *default_instance_;
}

SignCompRespond* SignCompRespond::default_instance_ = NULL;

SignCompRespond* SignCompRespond::New() const {
  return new SignCompRespond;
}

void SignCompRespond::Clear() {
  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    btoday_ = false;
    curtime_ = GOOGLE_ULONGLONG(0);
    badagenum_ = 0;
    getdays_ = 0;
    continuedays_ = 0;
    totaldays_ = 0;
    gainnum_ = 0;
    extranum_ = 0;
  }
  if (_has_bits_[9 / 32] & (0xffu << (9 % 32))) {
    signcost_ = 0;
    freetimes_ = 0;
    morrownum_ = 0;
  }
  bsign_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool SignCompRespond::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) return false
  ::google::protobuf::uint32 tag;
  while ((tag = input->ReadTag()) != 0) {
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional bool btoday = 1;
      case 1: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, &btoday_)));
          set_has_btoday();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(16)) goto parse_curtime;
        break;
      }

      // optional uint64 curtime = 2;
      case 2: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_curtime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::uint64, ::google::protobuf::internal::WireFormatLite::TYPE_UINT64>(
                 input, &curtime_)));
          set_has_curtime();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(24)) goto parse_badagenum;
        break;
      }

      // optional int32 badagenum = 3;
      case 3: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_badagenum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &badagenum_)));
          set_has_badagenum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(32)) goto parse_getdays;
        break;
      }

      // optional int32 getdays = 4;
      case 4: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_getdays:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &getdays_)));
          set_has_getdays();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(40)) goto parse_continuedays;
        break;
      }

      // optional int32 continuedays = 5;
      case 5: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_continuedays:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &continuedays_)));
          set_has_continuedays();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(48)) goto parse_totaldays;
        break;
      }

      // optional int32 totaldays = 6;
      case 6: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_totaldays:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &totaldays_)));
          set_has_totaldays();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(56)) goto parse_gainnum;
        break;
      }

      // optional int32 gainnum = 7;
      case 7: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_gainnum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &gainnum_)));
          set_has_gainnum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(64)) goto parse_extranum;
        break;
      }

      // optional int32 extranum = 8;
      case 8: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_extranum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &extranum_)));
          set_has_extranum();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_bsign;
        break;
      }

      // repeated bool bsign = 9;
      case 9: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_bsign:
          DO_((::google::protobuf::internal::WireFormatLite::ReadRepeatedPrimitive<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 1, 72, input, this->mutable_bsign())));
        } else if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag)
                   == ::google::protobuf::internal::WireFormatLite::
                      WIRETYPE_LENGTH_DELIMITED) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPackedPrimitiveNoInline<
                   bool, ::google::protobuf::internal::WireFormatLite::TYPE_BOOL>(
                 input, this->mutable_bsign())));
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(72)) goto parse_bsign;
        if (input->ExpectTag(80)) goto parse_signcost;
        break;
      }

      // optional int32 signcost = 10;
      case 10: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_signcost:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &signcost_)));
          set_has_signcost();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(88)) goto parse_freetimes;
        break;
      }

      // optional int32 freetimes = 11;
      case 11: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_freetimes:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &freetimes_)));
          set_has_freetimes();
        } else {
          goto handle_uninterpreted;
        }
        if (input->ExpectTag(96)) goto parse_morrownum;
        break;
      }

      // optional int32 morrownum = 12;
      case 12: {
        if (::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_VARINT) {
         parse_morrownum:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &morrownum_)));
          set_has_morrownum();
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

void SignCompRespond::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // optional bool btoday = 1;
  if (has_btoday()) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(1, this->btoday(), output);
  }

  // optional uint64 curtime = 2;
  if (has_curtime()) {
    ::google::protobuf::internal::WireFormatLite::WriteUInt64(2, this->curtime(), output);
  }

  // optional int32 badagenum = 3;
  if (has_badagenum()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->badagenum(), output);
  }

  // optional int32 getdays = 4;
  if (has_getdays()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->getdays(), output);
  }

  // optional int32 continuedays = 5;
  if (has_continuedays()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(5, this->continuedays(), output);
  }

  // optional int32 totaldays = 6;
  if (has_totaldays()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(6, this->totaldays(), output);
  }

  // optional int32 gainnum = 7;
  if (has_gainnum()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->gainnum(), output);
  }

  // optional int32 extranum = 8;
  if (has_extranum()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(8, this->extranum(), output);
  }

  // repeated bool bsign = 9;
  for (int i = 0; i < this->bsign_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteBool(
      9, this->bsign(i), output);
  }

  // optional int32 signcost = 10;
  if (has_signcost()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(10, this->signcost(), output);
  }

  // optional int32 freetimes = 11;
  if (has_freetimes()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->freetimes(), output);
  }

  // optional int32 morrownum = 12;
  if (has_morrownum()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(12, this->morrownum(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
}

::google::protobuf::uint8* SignCompRespond::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // optional bool btoday = 1;
  if (has_btoday()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteBoolToArray(1, this->btoday(), target);
  }

  // optional uint64 curtime = 2;
  if (has_curtime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteUInt64ToArray(2, this->curtime(), target);
  }

  // optional int32 badagenum = 3;
  if (has_badagenum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->badagenum(), target);
  }

  // optional int32 getdays = 4;
  if (has_getdays()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->getdays(), target);
  }

  // optional int32 continuedays = 5;
  if (has_continuedays()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(5, this->continuedays(), target);
  }

  // optional int32 totaldays = 6;
  if (has_totaldays()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(6, this->totaldays(), target);
  }

  // optional int32 gainnum = 7;
  if (has_gainnum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->gainnum(), target);
  }

  // optional int32 extranum = 8;
  if (has_extranum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(8, this->extranum(), target);
  }

  // repeated bool bsign = 9;
  for (int i = 0; i < this->bsign_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteBoolToArray(9, this->bsign(i), target);
  }

  // optional int32 signcost = 10;
  if (has_signcost()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, this->signcost(), target);
  }

  // optional int32 freetimes = 11;
  if (has_freetimes()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->freetimes(), target);
  }

  // optional int32 morrownum = 12;
  if (has_morrownum()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(12, this->morrownum(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  return target;
}

int SignCompRespond::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional bool btoday = 1;
    if (has_btoday()) {
      total_size += 1 + 1;
    }

    // optional uint64 curtime = 2;
    if (has_curtime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::UInt64Size(
          this->curtime());
    }

    // optional int32 badagenum = 3;
    if (has_badagenum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->badagenum());
    }

    // optional int32 getdays = 4;
    if (has_getdays()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->getdays());
    }

    // optional int32 continuedays = 5;
    if (has_continuedays()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->continuedays());
    }

    // optional int32 totaldays = 6;
    if (has_totaldays()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->totaldays());
    }

    // optional int32 gainnum = 7;
    if (has_gainnum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->gainnum());
    }

    // optional int32 extranum = 8;
    if (has_extranum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->extranum());
    }

  }
  if (_has_bits_[9 / 32] & (0xffu << (9 % 32))) {
    // optional int32 signcost = 10;
    if (has_signcost()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->signcost());
    }

    // optional int32 freetimes = 11;
    if (has_freetimes()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->freetimes());
    }

    // optional int32 morrownum = 12;
    if (has_morrownum()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->morrownum());
    }

  }
  // repeated bool bsign = 9;
  {
    int data_size = 0;
    data_size = 1 * this->bsign_size();
    total_size += 1 * this->bsign_size() + data_size;
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

void SignCompRespond::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const SignCompRespond* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const SignCompRespond*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void SignCompRespond::MergeFrom(const SignCompRespond& from) {
  GOOGLE_CHECK_NE(&from, this);
  bsign_.MergeFrom(from.bsign_);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_btoday()) {
      set_btoday(from.btoday());
    }
    if (from.has_curtime()) {
      set_curtime(from.curtime());
    }
    if (from.has_badagenum()) {
      set_badagenum(from.badagenum());
    }
    if (from.has_getdays()) {
      set_getdays(from.getdays());
    }
    if (from.has_continuedays()) {
      set_continuedays(from.continuedays());
    }
    if (from.has_totaldays()) {
      set_totaldays(from.totaldays());
    }
    if (from.has_gainnum()) {
      set_gainnum(from.gainnum());
    }
    if (from.has_extranum()) {
      set_extranum(from.extranum());
    }
  }
  if (from._has_bits_[9 / 32] & (0xffu << (9 % 32))) {
    if (from.has_signcost()) {
      set_signcost(from.signcost());
    }
    if (from.has_freetimes()) {
      set_freetimes(from.freetimes());
    }
    if (from.has_morrownum()) {
      set_morrownum(from.morrownum());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void SignCompRespond::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SignCompRespond::CopyFrom(const SignCompRespond& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SignCompRespond::IsInitialized() const {

  return true;
}

void SignCompRespond::Swap(SignCompRespond* other) {
  if (other != this) {
    std::swap(btoday_, other->btoday_);
    std::swap(curtime_, other->curtime_);
    std::swap(badagenum_, other->badagenum_);
    std::swap(getdays_, other->getdays_);
    std::swap(continuedays_, other->continuedays_);
    std::swap(totaldays_, other->totaldays_);
    std::swap(gainnum_, other->gainnum_);
    std::swap(extranum_, other->extranum_);
    bsign_.Swap(&other->bsign_);
    std::swap(signcost_, other->signcost_);
    std::swap(freetimes_, other->freetimes_);
    std::swap(morrownum_, other->morrownum_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata SignCompRespond::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SignCompRespond_descriptor_;
  metadata.reflection = SignCompRespond_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace Message

// @@protoc_insertion_point(global_scope)
