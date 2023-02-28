#pragma once

#include <memory>
#include <Util/Singleton.h>
#include <Util/ConfigConst.h>
#include <Util/EffectVal.h>
#include <Util/MaskVal.h>
#include <Util/Time.h>
#include <Layer/BlendMode.h>
#include <Resource/Resource.h>

namespace Comp
{
	class Composite;
	typedef std::shared_ptr<Composite> Sp_Composite;
}

namespace Editor
{

	struct CfgComposite
	{
		Util::Name compName;
		glm::ivec2 dimensions;
		float duration;
		float frameRate;
	};

	struct CfgFootage
	{
		Comp::Sp_Composite parent;
		Util::Path path;
	};

	typedef std::vector<std::pair<std::string, float>> KeyFloat1Vec;
	typedef std::vector<std::pair<std::string, glm::vec2>> KeyFloat2Vec;
	typedef std::vector<std::pair<std::string, glm::vec3>> KeyFloat3Vec;
	typedef std::vector<std::pair<std::string, glm::vec4>> KeyFloat4Vec;
	typedef std::vector<std::pair<std::string, uint32_t>> KeyInt1Vec;

	struct CfgEffect
	{
		Util::Name effectName;
		KeyFloat1Vec keyFloat1Vec;
		KeyFloat2Vec keyFloat2Vec;
		KeyFloat3Vec keyFloat3Vec;
		KeyFloat4Vec keyFloat4Vec;
		KeyInt1Vec keyInt1Vec;
	};

	struct VLTime
	{
		int32_t value;
		uint32_t scale;
	};

	struct CfgLayer
	{
		VLTime begin;
		VLTime duration;
	};

	class Mgr : public Util::Singleton<Mgr>
	{
	public:
		Mgr(Token) {}
		~Mgr() {}

		Res::Sp_Resource CreateResource(const Util::Path& path);
		Util::Handle CreateComposite(CfgComposite cfgComp);
		Util::Handle CreateFootage(CfgFootage cfgFtg);
		void AddComponent(Util::Handle composite, Util::Handle component, size_t layerIndex = -1);
		Util::Handle AddEffect(Util::Handle layerHandle, CfgEffect cfgEffect);

		//adjust
		void AdjustBeginTime(Util::Handle compositeHandle, size_t layerIndx, Editor::VLTime);

		//layer transform:
		void SetAnchorPoint(Util::Handle layerID, glm::vec2 anchorPoint);
		//other transform attribs

		//layer effect:
		void AddEffect(Util::Handle layerID, const Util::EffectVal& effectVal, size_t idx);
		void UpdateEffect(Util::Handle layerID, size_t idx, const Util::EffectVal& effectVal);

		//layer mask:
		void AddMask(Util::Handle layerID, Util::MaskVal maskVal, size_t idx);;

		//layer blending
		void SetBlending(Util::Handle layerID, Layer::BlendMode mode);

		//layer time
		void SetTime(Util::Handle layerID, Util::Time start, Util::Time duration);

		//other layer attribs

	};

}