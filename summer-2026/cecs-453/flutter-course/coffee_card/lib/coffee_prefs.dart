import 'package:flutter/material.dart';
import 'package:coffee_card/styled_body_text.dart';
import 'package:coffee_card/styled_button.dart';

class CoffeePrefs extends StatefulWidget {
  const CoffeePrefs({super.key});

  @override
  State<CoffeePrefs> createState() => _CoffeePrefsState();
}

class _CoffeePrefsState extends State<CoffeePrefs> {
  int strength = 1;
  int sugars = 0;

  void incrementStrength() {
    setState(() {
      strength = (strength % 5) + 1;
    });
  }

  void incrementSugars() {
    setState(() {
      sugars = ((sugars + 1) % 6);
    });
  }

  @override
  Widget build(BuildContext context) {
    final coffeeBeanImage = Image.asset(
      'assets/img/coffee_bean.png',
      width: 25,
      color: Colors.brown[100],
      colorBlendMode: BlendMode.multiply,
    );

    List<Widget> strengthImages = [];

    for (int i = 0; i < strength; i++) {
      strengthImages.add(coffeeBeanImage);
    }

    final sugarImage = Image.asset(
      'assets/img/sugar_cube.png',
      width: 25,
      color: Colors.brown[100],
      colorBlendMode: BlendMode.multiply,
    );

    List<Widget> sugarImages = [];

    if (sugars == 0) {
      sugarImages.add(StyledBodyText('No sugar...'));
    }

    for (int i = 0; i < sugars; i++) {
      sugarImages.add(sugarImage);
    }

    return Column(
      children: [
        Row(
          children: [
            StyledBodyText('Strength: '),
            ...strengthImages,
            Expanded(child: SizedBox()),
            StyledButton(onPressed: incrementStrength, child: Text('+')),
          ],
        ),
        Row(
          children: [
            StyledBodyText('Sugars: '),
            ...sugarImages,
            Expanded(child: SizedBox()),
            StyledButton(onPressed: incrementSugars, child: Text('+')),
          ],
        ),
      ],
    );
  }
}
