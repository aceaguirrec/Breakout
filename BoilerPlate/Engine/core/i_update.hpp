#pragma once
#ifndef _I_UPDATE_HPP_
#define _I_UPDATE_HPP_

namespace engine
{
	namespace core
	{
		class i_update {
		public:
			/* =============================================================
			* CTOR
			* ============================================================= */
			i_update() : m_nUpdates(0) {}
			virtual ~i_update() = default;

			/* =============================================================
			* PUBLIC FUNCTIONS
			* ============================================================= */
			void virtual update(double deltaTime) { m_nUpdates++; };
		protected:
			/* =============================================================
			* MEMBERS
			* ============================================================= */
			int	m_nUpdates;
		};
	}
}
#endif // !_IUPDATE_HPP_
