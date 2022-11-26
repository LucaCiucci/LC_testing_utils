#pragma once


namespace lc
{
	namespace
	{
		class MoveGuardBase
		{
			static size_t id_counter = 0;

		public:

			MoveGuardBase() = default;
			MoveGuardBase(const MoveGuardBase&) : MoveGuardBase() {};
			MoveGuardBase(MoveGuardBase&&) = default;

			MoveGuardBase& operator=(const MoveGuardBase&) {
				return *this;
			}

			MoveGuardBase& operator=(MoveGuardBase&&) = default;

			size_t id() const { return m_id; }

		private:
			size_t m_id = id_counter++;
		};

		template <typename T>
		class MoveGuard : public MoveGuardBase
		{
			T m_value;
			
		public:
			
			MoveGuard() = default;
			MoveGuard(const MoveGuard&) = default;
			MoveGuard(MoveGuard&& other) : MoveGuardBase(std::move(other)), m_value(std::move(other.m_value)) {}

			MoveGuard& operator=(const MoveGuard& other) {
				MoveGuardBase::operator=(other);
				m_value = other.m_value;
				return *this;
			}
			MoveGuard& operator=(MoveGuard&& other) {
				MoveGuardBase::operator=(std::move(other));
				m_value = std::move(other.m_value);
				return *this;
			}

			T& value() { return m_value; }
			const T& value() const { return m_value; }
		};
	}
}