// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: tracker.proto
// Protobuf C++ Version: 5.29.3

#ifndef tracker_2eproto_2epb_2eh
#define tracker_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5029003
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/message_lite.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_tracker_2eproto

namespace google {
namespace protobuf {
namespace internal {
template <typename T>
::absl::string_view GetAnyMessageName();
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_tracker_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_tracker_2eproto;
class tracker;
struct trackerDefaultTypeInternal;
extern trackerDefaultTypeInternal _tracker_default_instance_;
class tracker_list;
struct tracker_listDefaultTypeInternal;
extern tracker_listDefaultTypeInternal _tracker_list_default_instance_;
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google


// ===================================================================


// -------------------------------------------------------------------

class tracker final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tracker) */ {
 public:
  inline tracker() : tracker(nullptr) {}
  ~tracker() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(tracker* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(tracker));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR tracker(
      ::google::protobuf::internal::ConstantInitialized);

  inline tracker(const tracker& from) : tracker(nullptr, from) {}
  inline tracker(tracker&& from) noexcept
      : tracker(nullptr, std::move(from)) {}
  inline tracker& operator=(const tracker& from) {
    CopyFrom(from);
    return *this;
  }
  inline tracker& operator=(tracker&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const tracker& default_instance() {
    return *internal_default_instance();
  }
  static inline const tracker* internal_default_instance() {
    return reinterpret_cast<const tracker*>(
        &_tracker_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(tracker& a, tracker& b) { a.Swap(&b); }
  inline void Swap(tracker* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(tracker* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  tracker* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<tracker>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const tracker& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const tracker& from) { tracker::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(tracker* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tracker"; }

 protected:
  explicit tracker(::google::protobuf::Arena* arena);
  tracker(::google::protobuf::Arena* arena, const tracker& from);
  tracker(::google::protobuf::Arena* arena, tracker&& from) noexcept
      : tracker(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kCoordinatesFieldNumber = 3,
    kIdFieldNumber = 6,
    kTimeTrackFieldNumber = 7,
    kNameFieldNumber = 8,
    kLongitudeFieldNumber = 9,
    kLatitudeFieldNumber = 10,
    kSpeedFieldNumber = 1,
    kBatteryFieldNumber = 2,
    kPowerFieldNumber = 5,
  };
  // string coordinates = 3;
  void clear_coordinates() ;
  const std::string& coordinates() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_coordinates(Arg_&& arg, Args_... args);
  std::string* mutable_coordinates();
  PROTOBUF_NODISCARD std::string* release_coordinates();
  void set_allocated_coordinates(std::string* value);

  private:
  const std::string& _internal_coordinates() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_coordinates(
      const std::string& value);
  std::string* _internal_mutable_coordinates();

  public:
  // string id = 6;
  void clear_id() ;
  const std::string& id() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_id(Arg_&& arg, Args_... args);
  std::string* mutable_id();
  PROTOBUF_NODISCARD std::string* release_id();
  void set_allocated_id(std::string* value);

  private:
  const std::string& _internal_id() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_id(
      const std::string& value);
  std::string* _internal_mutable_id();

  public:
  // string time_track = 7;
  void clear_time_track() ;
  const std::string& time_track() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_time_track(Arg_&& arg, Args_... args);
  std::string* mutable_time_track();
  PROTOBUF_NODISCARD std::string* release_time_track();
  void set_allocated_time_track(std::string* value);

  private:
  const std::string& _internal_time_track() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_time_track(
      const std::string& value);
  std::string* _internal_mutable_time_track();

  public:
  // string name = 8;
  void clear_name() ;
  const std::string& name() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_name(Arg_&& arg, Args_... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* value);

  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(
      const std::string& value);
  std::string* _internal_mutable_name();

  public:
  // string longitude = 9;
  void clear_longitude() ;
  const std::string& longitude() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_longitude(Arg_&& arg, Args_... args);
  std::string* mutable_longitude();
  PROTOBUF_NODISCARD std::string* release_longitude();
  void set_allocated_longitude(std::string* value);

  private:
  const std::string& _internal_longitude() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_longitude(
      const std::string& value);
  std::string* _internal_mutable_longitude();

  public:
  // string latitude = 10;
  void clear_latitude() ;
  const std::string& latitude() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_latitude(Arg_&& arg, Args_... args);
  std::string* mutable_latitude();
  PROTOBUF_NODISCARD std::string* release_latitude();
  void set_allocated_latitude(std::string* value);

  private:
  const std::string& _internal_latitude() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_latitude(
      const std::string& value);
  std::string* _internal_mutable_latitude();

  public:
  // int32 speed = 1;
  void clear_speed() ;
  ::int32_t speed() const;
  void set_speed(::int32_t value);

  private:
  ::int32_t _internal_speed() const;
  void _internal_set_speed(::int32_t value);

  public:
  // int32 battery = 2;
  void clear_battery() ;
  ::int32_t battery() const;
  void set_battery(::int32_t value);

  private:
  ::int32_t _internal_battery() const;
  void _internal_set_battery(::int32_t value);

  public:
  // bool power = 5;
  void clear_power() ;
  bool power() const;
  void set_power(bool value);

  private:
  bool _internal_power() const;
  void _internal_set_power(bool value);

  public:
  // @@protoc_insertion_point(class_scope:tracker)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      4, 9, 0,
      68, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const tracker& from_msg);
    ::google::protobuf::internal::ArenaStringPtr coordinates_;
    ::google::protobuf::internal::ArenaStringPtr id_;
    ::google::protobuf::internal::ArenaStringPtr time_track_;
    ::google::protobuf::internal::ArenaStringPtr name_;
    ::google::protobuf::internal::ArenaStringPtr longitude_;
    ::google::protobuf::internal::ArenaStringPtr latitude_;
    ::int32_t speed_;
    ::int32_t battery_;
    bool power_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tracker_2eproto;
};
// -------------------------------------------------------------------

class tracker_list final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:tracker_list) */ {
 public:
  inline tracker_list() : tracker_list(nullptr) {}
  ~tracker_list() PROTOBUF_FINAL;

#if defined(PROTOBUF_CUSTOM_VTABLE)
  void operator delete(tracker_list* msg, std::destroying_delete_t) {
    SharedDtor(*msg);
    ::google::protobuf::internal::SizedDelete(msg, sizeof(tracker_list));
  }
#endif

  template <typename = void>
  explicit PROTOBUF_CONSTEXPR tracker_list(
      ::google::protobuf::internal::ConstantInitialized);

  inline tracker_list(const tracker_list& from) : tracker_list(nullptr, from) {}
  inline tracker_list(tracker_list&& from) noexcept
      : tracker_list(nullptr, std::move(from)) {}
  inline tracker_list& operator=(const tracker_list& from) {
    CopyFrom(from);
    return *this;
  }
  inline tracker_list& operator=(tracker_list&& from) noexcept {
    if (this == &from) return *this;
    if (::google::protobuf::internal::CanMoveWithInternalSwap(GetArena(), from.GetArena())) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const tracker_list& default_instance() {
    return *internal_default_instance();
  }
  static inline const tracker_list* internal_default_instance() {
    return reinterpret_cast<const tracker_list*>(
        &_tracker_list_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(tracker_list& a, tracker_list& b) { a.Swap(&b); }
  inline void Swap(tracker_list* other) {
    if (other == this) return;
    if (::google::protobuf::internal::CanUseInternalSwap(GetArena(), other->GetArena())) {
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(tracker_list* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  tracker_list* New(::google::protobuf::Arena* arena = nullptr) const {
    return ::google::protobuf::Message::DefaultConstruct<tracker_list>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const tracker_list& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const tracker_list& from) { tracker_list::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() PROTOBUF_FINAL;
  #if defined(PROTOBUF_CUSTOM_VTABLE)
  private:
  static ::size_t ByteSizeLong(const ::google::protobuf::MessageLite& msg);
  static ::uint8_t* _InternalSerialize(
      const MessageLite& msg, ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream);

  public:
  ::size_t ByteSizeLong() const { return ByteSizeLong(*this); }
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const {
    return _InternalSerialize(*this, target, stream);
  }
  #else   // PROTOBUF_CUSTOM_VTABLE
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  #endif  // PROTOBUF_CUSTOM_VTABLE
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  static void SharedDtor(MessageLite& self);
  void InternalSwap(tracker_list* other);
 private:
  template <typename T>
  friend ::absl::string_view(
      ::google::protobuf::internal::GetAnyMessageName)();
  static ::absl::string_view FullMessageName() { return "tracker_list"; }

 protected:
  explicit tracker_list(::google::protobuf::Arena* arena);
  tracker_list(::google::protobuf::Arena* arena, const tracker_list& from);
  tracker_list(::google::protobuf::Arena* arena, tracker_list&& from) noexcept
      : tracker_list(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::internal::ClassData* GetClassData() const PROTOBUF_FINAL;
  static void* PlacementNew_(const void*, void* mem,
                             ::google::protobuf::Arena* arena);
  static constexpr auto InternalNewImpl_();
  static const ::google::protobuf::internal::ClassDataFull _class_data_;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kTrackersFieldNumber = 1,
  };
  // repeated .tracker trackers = 1;
  int trackers_size() const;
  private:
  int _internal_trackers_size() const;

  public:
  void clear_trackers() ;
  ::tracker* mutable_trackers(int index);
  ::google::protobuf::RepeatedPtrField<::tracker>* mutable_trackers();

  private:
  const ::google::protobuf::RepeatedPtrField<::tracker>& _internal_trackers() const;
  ::google::protobuf::RepeatedPtrField<::tracker>* _internal_mutable_trackers();
  public:
  const ::tracker& trackers(int index) const;
  ::tracker* add_trackers();
  const ::google::protobuf::RepeatedPtrField<::tracker>& trackers() const;
  // @@protoc_insertion_point(class_scope:tracker_list)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 1,
      0, 2>
      _table_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const tracker_list& from_msg);
    ::google::protobuf::RepeatedPtrField< ::tracker > trackers_;
    ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tracker_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// tracker

// int32 speed = 1;
inline void tracker::clear_speed() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.speed_ = 0;
}
inline ::int32_t tracker::speed() const {
  // @@protoc_insertion_point(field_get:tracker.speed)
  return _internal_speed();
}
inline void tracker::set_speed(::int32_t value) {
  _internal_set_speed(value);
  // @@protoc_insertion_point(field_set:tracker.speed)
}
inline ::int32_t tracker::_internal_speed() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.speed_;
}
inline void tracker::_internal_set_speed(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.speed_ = value;
}

// int32 battery = 2;
inline void tracker::clear_battery() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.battery_ = 0;
}
inline ::int32_t tracker::battery() const {
  // @@protoc_insertion_point(field_get:tracker.battery)
  return _internal_battery();
}
inline void tracker::set_battery(::int32_t value) {
  _internal_set_battery(value);
  // @@protoc_insertion_point(field_set:tracker.battery)
}
inline ::int32_t tracker::_internal_battery() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.battery_;
}
inline void tracker::_internal_set_battery(::int32_t value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.battery_ = value;
}

// string coordinates = 3;
inline void tracker::clear_coordinates() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.coordinates_.ClearToEmpty();
}
inline const std::string& tracker::coordinates() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.coordinates)
  return _internal_coordinates();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_coordinates(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.coordinates_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.coordinates)
}
inline std::string* tracker::mutable_coordinates() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_coordinates();
  // @@protoc_insertion_point(field_mutable:tracker.coordinates)
  return _s;
}
inline const std::string& tracker::_internal_coordinates() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.coordinates_.Get();
}
inline void tracker::_internal_set_coordinates(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.coordinates_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_coordinates() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.coordinates_.Mutable( GetArena());
}
inline std::string* tracker::release_coordinates() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.coordinates)
  return _impl_.coordinates_.Release();
}
inline void tracker::set_allocated_coordinates(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.coordinates_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.coordinates_.IsDefault()) {
    _impl_.coordinates_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.coordinates)
}

// bool power = 5;
inline void tracker::clear_power() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.power_ = false;
}
inline bool tracker::power() const {
  // @@protoc_insertion_point(field_get:tracker.power)
  return _internal_power();
}
inline void tracker::set_power(bool value) {
  _internal_set_power(value);
  // @@protoc_insertion_point(field_set:tracker.power)
}
inline bool tracker::_internal_power() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.power_;
}
inline void tracker::_internal_set_power(bool value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.power_ = value;
}

// string id = 6;
inline void tracker::clear_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.id_.ClearToEmpty();
}
inline const std::string& tracker::id() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.id)
  return _internal_id();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_id(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.id_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.id)
}
inline std::string* tracker::mutable_id() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_id();
  // @@protoc_insertion_point(field_mutable:tracker.id)
  return _s;
}
inline const std::string& tracker::_internal_id() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.id_.Get();
}
inline void tracker::_internal_set_id(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.id_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.id_.Mutable( GetArena());
}
inline std::string* tracker::release_id() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.id)
  return _impl_.id_.Release();
}
inline void tracker::set_allocated_id(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.id_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.id_.IsDefault()) {
    _impl_.id_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.id)
}

// string time_track = 7;
inline void tracker::clear_time_track() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.time_track_.ClearToEmpty();
}
inline const std::string& tracker::time_track() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.time_track)
  return _internal_time_track();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_time_track(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.time_track_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.time_track)
}
inline std::string* tracker::mutable_time_track() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_time_track();
  // @@protoc_insertion_point(field_mutable:tracker.time_track)
  return _s;
}
inline const std::string& tracker::_internal_time_track() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.time_track_.Get();
}
inline void tracker::_internal_set_time_track(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.time_track_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_time_track() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.time_track_.Mutable( GetArena());
}
inline std::string* tracker::release_time_track() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.time_track)
  return _impl_.time_track_.Release();
}
inline void tracker::set_allocated_time_track(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.time_track_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.time_track_.IsDefault()) {
    _impl_.time_track_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.time_track)
}

// string name = 8;
inline void tracker::clear_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.ClearToEmpty();
}
inline const std::string& tracker::name() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.name)
  return _internal_name();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_name(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.name)
}
inline std::string* tracker::mutable_name() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:tracker.name)
  return _s;
}
inline const std::string& tracker::_internal_name() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.name_.Get();
}
inline void tracker::_internal_set_name(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.name_.Mutable( GetArena());
}
inline std::string* tracker::release_name() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.name)
  return _impl_.name_.Release();
}
inline void tracker::set_allocated_name(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.name_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.name)
}

// string longitude = 9;
inline void tracker::clear_longitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.longitude_.ClearToEmpty();
}
inline const std::string& tracker::longitude() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.longitude)
  return _internal_longitude();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_longitude(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.longitude_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.longitude)
}
inline std::string* tracker::mutable_longitude() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_longitude();
  // @@protoc_insertion_point(field_mutable:tracker.longitude)
  return _s;
}
inline const std::string& tracker::_internal_longitude() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.longitude_.Get();
}
inline void tracker::_internal_set_longitude(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.longitude_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_longitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.longitude_.Mutable( GetArena());
}
inline std::string* tracker::release_longitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.longitude)
  return _impl_.longitude_.Release();
}
inline void tracker::set_allocated_longitude(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.longitude_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.longitude_.IsDefault()) {
    _impl_.longitude_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.longitude)
}

// string latitude = 10;
inline void tracker::clear_latitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.latitude_.ClearToEmpty();
}
inline const std::string& tracker::latitude() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker.latitude)
  return _internal_latitude();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void tracker::set_latitude(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.latitude_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:tracker.latitude)
}
inline std::string* tracker::mutable_latitude() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_latitude();
  // @@protoc_insertion_point(field_mutable:tracker.latitude)
  return _s;
}
inline const std::string& tracker::_internal_latitude() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.latitude_.Get();
}
inline void tracker::_internal_set_latitude(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.latitude_.Set(value, GetArena());
}
inline std::string* tracker::_internal_mutable_latitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.latitude_.Mutable( GetArena());
}
inline std::string* tracker::release_latitude() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:tracker.latitude)
  return _impl_.latitude_.Release();
}
inline void tracker::set_allocated_latitude(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.latitude_.SetAllocated(value, GetArena());
  if (::google::protobuf::internal::DebugHardenForceCopyDefaultString() && _impl_.latitude_.IsDefault()) {
    _impl_.latitude_.Set("", GetArena());
  }
  // @@protoc_insertion_point(field_set_allocated:tracker.latitude)
}

// -------------------------------------------------------------------

// tracker_list

// repeated .tracker trackers = 1;
inline int tracker_list::_internal_trackers_size() const {
  return _internal_trackers().size();
}
inline int tracker_list::trackers_size() const {
  return _internal_trackers_size();
}
inline void tracker_list::clear_trackers() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.trackers_.Clear();
}
inline ::tracker* tracker_list::mutable_trackers(int index)
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable:tracker_list.trackers)
  return _internal_mutable_trackers()->Mutable(index);
}
inline ::google::protobuf::RepeatedPtrField<::tracker>* tracker_list::mutable_trackers()
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_mutable_list:tracker_list.trackers)
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _internal_mutable_trackers();
}
inline const ::tracker& tracker_list::trackers(int index) const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:tracker_list.trackers)
  return _internal_trackers().Get(index);
}
inline ::tracker* tracker_list::add_trackers() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  ::tracker* _add = _internal_mutable_trackers()->Add();
  // @@protoc_insertion_point(field_add:tracker_list.trackers)
  return _add;
}
inline const ::google::protobuf::RepeatedPtrField<::tracker>& tracker_list::trackers() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_list:tracker_list.trackers)
  return _internal_trackers();
}
inline const ::google::protobuf::RepeatedPtrField<::tracker>&
tracker_list::_internal_trackers() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.trackers_;
}
inline ::google::protobuf::RepeatedPtrField<::tracker>*
tracker_list::_internal_mutable_trackers() {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return &_impl_.trackers_;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // tracker_2eproto_2epb_2eh
