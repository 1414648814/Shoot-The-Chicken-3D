
/***********************************************************************

                           �ࣺNOISE Light Engine

			��������Ҫ����������ĵƹ⣬����������µ�GPU

************************************************************************/

#include "MyConsoleEngine.h"

ILightManager::ILightManager()
{
	m_pLightList	= new std::vector<IDirectionalLight*>;
}

void ILightManager::Destroy()
{

};

//��Щ�ù�add remove ����macro��
void	ILightManager::AddLight(IDirectionalLight& refLight)
{
	mFunction_AddLight<IDirectionalLight*>(m_pLightList, &refLight,10);
};

void	ILightManager::RemoveLight(IDirectionalLight& refLight)
{
	mFunction_RemoveLight_ByAddr<IDirectionalLight*>(m_pLightList, &refLight);
}

IDirectionalLight* ILightManager::GetLight(UINT index)
{
	if (index < m_pLightList->size())
	{
		return  m_pLightList->at(index);
	}
	return nullptr;
};

UINT	 ILightManager::GetTotalLightCount()
{
	return m_pLightList->size();
};


/***********************************************************************
								PRIVATE					                    
***********************************************************************/
template <typename T> 
void ILightManager::mFunction_AddLight(std::vector<T>* pList, T iLight,UINT maxElementCount)
{
	std::vector<T>::iterator tmp_iter; 
		for(tmp_iter = pList->begin();	tmp_iter != pList->end(); tmp_iter++) 
		{ 
		//�ҵ��ظ��ĵƹ�Ͳ�add��
		if(*tmp_iter == iLight) return; 
		}; 
		if ( pList->size() < maxElementCount) pList->push_back(iLight); 
};

template <typename T> 
void ILightManager::mFunction_RemoveLight_ByAddr(std::vector<T>* pList, T DelLight)
{
	std::vector<T>::iterator tmp_iter; 
	for(tmp_iter = pList->begin();	tmp_iter != pList->end(); tmp_iter++) 
	{ 
	//��vector��ǰλ�õĿ�λ�����ݶ�Ĩ��
	if(*tmp_iter == DelLight){tmp_iter = pList->erase(tmp_iter);break;} 
	}; 
};

template <typename T> 
void ILightManager::mFunction_RemoveLight_ByIndex(std::vector<T>* pList, UINT lightIndex)
{
	std::vector<T>::iterator tmp_iter = pList->begin(); 
		if(pList->size() > lightIndex) 
		{ 
			tmp_iter += lightIndex; 
			pList->erase(tmp_iter);  
		} 
};
