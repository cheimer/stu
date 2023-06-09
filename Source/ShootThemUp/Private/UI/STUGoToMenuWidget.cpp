// Shoot Them Up Game, All Rights Reserved.


#include "UI/STUGoToMenuWidget.h"
#include "Components/Button.h"
#include "STUGameInstance.h"
#include "Kismet/GameplayStatics.h"

void USTUGoToMenuWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	if (GoToMenuButton)
	{
		GoToMenuButton->OnClicked.AddDynamic(this, &USTUGoToMenuWidget::OnGoToMenu);
	}

}

void USTUGoToMenuWidget::OnGoToMenu()
{
	if (!GetWorld()) return;

	const auto GameInstance = GetWorld()->GetGameInstance<USTUGameInstance>();
	if (!GameInstance) return;

	if (GameInstance->GetMenuLevelName().IsNone())
	{
		return;
	}

	UGameplayStatics::OpenLevel(this, GameInstance->GetMenuLevelName());
}