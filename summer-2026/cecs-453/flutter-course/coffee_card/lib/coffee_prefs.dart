import 'package:flutter/material.dart';

class CoffeePrefs extends StatelessWidget {
  const CoffeePrefs({super.key});

  void incrementStrength() {
    print('incrementStrength');
  }

  void incrementSugars() {
    print('incrementSugars');
  }

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Row(
          children: [
            Text('Strength: '),
            Text('1'),
            Image.asset(
              'assets/img/coffee_bean.png',
              width: 25,
              color: Colors.brown[100],
              colorBlendMode: BlendMode.multiply,
            ),
            Expanded(child: SizedBox()),
            ElevatedButton(onPressed: incrementStrength, child: Text('+')),
          ],
        ),
        Row(
          children: [
            Text('Sugars: '),
            Text('2'),
            Image.asset(
              'assets/img/sugar_cube.png',
              width: 25,
              color: Colors.brown[100],
              colorBlendMode: BlendMode.multiply,
            ),
            Expanded(child: SizedBox()),
            ElevatedButton(onPressed: incrementSugars, child: Text('+')),
          ],
        ),
      ],
    );
  }
}
